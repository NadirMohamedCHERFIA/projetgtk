#include "usersList.h"
void handleUserClickedOn(GtkWidget *butt, gpointer data)
{
    g_print("clicked");
    composedWindow *App = (composedWindow *)data;
    g_print("id: %d", App->id);

}

void handle_users(gpointer data)
{
    MainWindow *App = (MainWindow *)data;
    g_print("\nHandeling users, total:%d\n", App->numberOfUsers);
    for (int i = 0; i < App->numberOfUsers; i++)
    {
        App->users_hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 400);
        gtk_box_pack_start(GTK_BOX(App->welcome_vbox_users), App->users_hbox[i], FALSE, FALSE, 0);
        App->user_label[i] = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(App->user_label[i]), App->users[i]);
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_label[i], FALSE, FALSE, 0);
        gtk_widget_set_size_request(App->users_hbox[i], 1000, 60);
        App->user_select_button[i] = gtk_button_new_with_label("Select user");
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_select_button[i], FALSE, TRUE, 0);
        composedWindow *composedwindow;
        composedwindow = g_malloc(sizeof(composedWindow));
        composedwindow->App = App;
        composedwindow->id = i;
        strcpy(composedwindow->name,App->users[i]);
        g_signal_connect(G_OBJECT(App->user_select_button[i]), "clicked", G_CALLBACK(create_dashboard), (gpointer)composedwindow);
        App->user_delete_button[i] = gtk_button_new_with_label("Delete");
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_delete_button[i], FALSE, TRUE, 0);

        gtk_widget_set_name(App->user_delete_button[i], "user_delete_button");
        g_signal_connect(G_OBJECT(App->user_delete_button[i]),"clicked",G_CALLBACK(handleDeleteUser),(gpointer)composedwindow);
        g_print("\nAdding the %d user\n", i);
    }
}
void handle_adding_new_user(gpointer data)
{
    MainWindow *App = (MainWindow *)data;
    App->user_label[App->numberOfUsers - 1] = gtk_label_new(NULL);
    g_print("\nAdded the %d user OK", App->numberOfUsers);
    gtk_label_set_markup(GTK_LABEL(App->user_label[App->numberOfUsers - 1]), "NEW");
    gtk_widget_show(App->welcome_vbox_users);
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox_users), App->user_label[App->numberOfUsers - 1], FALSE, FALSE, 0);
}

void handleDeleteUser(GtkWidget *butt,gpointer data){
    composedWindow *compApp;
    compApp = (composedWindow*) data;
    GtkWidget *dialog;
    GtkWidget *dialogContainer;
    GtkWidget *dialogLabel;
    GtkWidget *hbox;
    GtkWidget *confirmButton;
    GtkWidget *cancelButton;

    char dialogMessage[255];
    MainWindow *App = compApp->App;
    char name[100];
    strcpy(name,compApp->name);
    sprintf(dialogMessage,"Vous voulez vraiment supprimer l'utilisateur : %s",name);
    strcat(dialogMessage,"?");
    gint id = compApp->id;
    g_print("handel deleting id : %d name: %s",id,name);
    // deleteUser(name);
    // handle_users(App);
    confirmButton = gtk_button_new_with_label("Confirmer");
    cancelButton = gtk_button_new_with_label("Cancel");
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);

    dialog = gtk_dialog_new();
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_window_set_title(GTK_WINDOW(dialog),"Confimer le suppression de l'utilisateur!");
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);
    gtk_widget_set_size_request(dialog,800,200);
    dialogLabel = gtk_label_new(dialogMessage);
    gtk_container_add(GTK_CONTAINER(dialogContainer), dialogLabel);
    gtk_container_add(GTK_CONTAINER(dialogContainer),hbox);
    gtk_box_pack_start(GTK_BOX(hbox),confirmButton,FALSE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(hbox), cancelButton, FALSE, TRUE, 0);
    compApp->dialog = dialog;
    g_signal_connect(G_OBJECT(confirmButton),"clicked",G_CALLBACK(confirm_delete_user),(gpointer)compApp);
    g_signal_connect(G_OBJECT(cancelButton), "clicked", G_CALLBACK(handle_cancel_delete), (gpointer)dialog);

    gtk_widget_show_all(dialog);
}

void confirm_delete_user(GtkWidget *butt,gpointer data){
    composedWindow *comApp;
    comApp = (composedWindow*)data;
    GtkWidget *dialog;
    dialog = comApp->dialog;
    char *name;
    strcpy(name,comApp->name);
    g_print("\nname:%s",name);
    deleteUser(name);
    gtk_window_close(GTK_WINDOW(dialog));
}

void handle_cancel_delete(GtkWidget *butt, gpointer data){
    GtkWidget *dialog;
    dialog = (GtkWidget*)data;
    gtk_window_close(GTK_WINDOW(dialog));
}