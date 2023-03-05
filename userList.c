#include "usersList.h"
void handleUserClickedOn(GtkWidget *butt, gpointer data)
{
    g_print("clicked");
    composedWindow *App = (composedWindow *)data;
    // g_print("id: %d", App->id);

}

void handle_users(gpointer data)
{
    int i=0;
    MainWindow *App = (MainWindow *)data;
    gint MAINWINDOWWIDTH = getScreenWidth();
    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWBORDERWIDTH =30;

    GList *children = gtk_container_get_children(GTK_CONTAINER(App->welcome_vbox_users));
    for(GList *iter =children; iter!=NULL; iter=iter->next){
        GtkWidget *child = GTK_WIDGET(iter->data);
        gtk_widget_destroy(child);
    }
    for (i = 0; i < App->numberOfUsers; i++)
    {
        App->users_hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
        gtk_widget_set_size_request(App->users_hbox[i], MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 2), MAINWINDOWHEIGHT * 0.1);
        gtk_box_pack_start(GTK_BOX(App->welcome_vbox_users), App->users_hbox[i], TRUE, FALSE, 0);
        gtk_widget_set_name(App->users_hbox[i],"user_hbox");

        App->user_label[i] = gtk_label_new(NULL);
        gtk_label_set_markup(GTK_LABEL(App->user_label[i]), App->users[i]);
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_label[i], TRUE, FALSE, 0);
        gtk_widget_set_size_request(App->user_label[i], (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 2))*0.2, MAINWINDOWHEIGHT * 0.1);
        App->user_select_button[i] = gtk_button_new_with_label("Select user");
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_select_button[i], TRUE, FALSE, 0);

        gtk_widget_set_name(App->user_select_button[i],"select__button");

        composedWindow *composedwindow;
        composedwindow = g_malloc(sizeof(composedWindow));
        composedwindow->App = App;
        // composedwindow->id = i;
        strcpy(composedwindow->name,App->users[i]);
        g_signal_connect(G_OBJECT(App->user_select_button[i]), "clicked", G_CALLBACK(createSignUp), (gpointer)composedwindow);
        gtk_widget_set_size_request(App->user_select_button[i], (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.2, MAINWINDOWHEIGHT * 0.1);

        App->user_delete_button[i] = gtk_button_new_with_label("Delete");
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_delete_button[i], FALSE, TRUE, 0);
        gtk_widget_set_size_request(App->user_delete_button[i], (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.2, MAINWINDOWHEIGHT * 0.1);

        gtk_widget_set_name(App->user_delete_button[i], "user_delete_button");
        g_signal_connect(G_OBJECT(App->user_delete_button[i]),"clicked",G_CALLBACK(handleDeleteUser),(gpointer)composedwindow);
        g_print("\nAdding the %d user\n", i);
    }
    // gtk_widget_show_all(App->welcome_vbox_users);
}
void handle_adding_new_user(gpointer data)
{
    MainWindow *App = (MainWindow *)data;
    App->user_label[App->numberOfUsers - 1] = gtk_label_new(NULL);
    // g_print("\nAdded the %d user OK", App->numberOfUsers);
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
    gint response;

    char dialogMessage[255];
    MainWindow *App = compApp->App;
    char name[100];
    strcpy(name,compApp->name);
    sprintf(dialogMessage,"Vous voulez vraiment supprimer l'utilisateur : %s",name);
    strcat(dialogMessage,"?");
    gint id = compApp->id;
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    dialog = gtk_dialog_new();
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_window_set_title(GTK_WINDOW(dialog),"Confimer le suppression de l'utilisateur!");
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);
    gtk_widget_set_size_request(dialog,800,50);
    dialogLabel = gtk_label_new(dialogMessage);
    gtk_container_add(GTK_CONTAINER(dialogContainer), dialogLabel);
    gtk_dialog_add_buttons(GTK_DIALOG(dialog),"Oui",1,"Non",2,NULL);
    gtk_widget_show_all(dialog);
    response = gtk_dialog_run(GTK_DIALOG(dialog));
    switch(response){
        case 1:
        deleteUser(name);
        get_users(compApp);
        handle_users(App);
        gtk_widget_show_all(App->welcome_window);
        gtk_widget_destroy(dialog);
        break;
        case 2:
            gtk_widget_destroy(dialog);
        break;
        default:
            break;
    }

}

// void confirm_delete_user(GtkWidget *butt,gpointer data){
//     composedWindow *comApp;
//     comApp = (composedWindow*)data;
//     GtkWidget *dialog;
//     dialog = comApp->dialog;
//     char *name;
//     strcpy(name,comApp->name);
//     // gdk_window_destroy(GTK_WINDOW(dialog));
//     // gtk_widget_destroy(dialog);
//     // deleteUser(name);
//     // get_users(comApp->App);
//     // handle_users(comApp->App);
//     // gtk_window_close(GTK_WINDOW(dialog));
//     // gtk_widget_show_all(comApp->App->welcome_window);
// }

void handle_cancel_delete(GtkWidget *butt, gpointer data){
    GtkWidget *dialog;
    dialog = (GtkWidget*)data;
    gtk_window_close(GTK_WINDOW(dialog));
}