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
        composedWindow *composedWindow;
        composedWindow = g_malloc(sizeof(composedWindow));
        composedWindow->App = App;
        composedWindow->id = i;
        g_signal_connect(G_OBJECT(App->user_select_button[i]), "clicked", G_CALLBACK(create_dashboard), (gpointer)composedWindow);
        App->user_delete_button[i] = gtk_button_new_with_label("Delete");
        gtk_box_pack_start(GTK_BOX(App->users_hbox[i]), App->user_delete_button[i], FALSE, TRUE, 0);

        gtk_widget_set_name(App->user_delete_button[i], "user_delete_button");
        // gtk_widget_set_name(App->user_delete_button[i], "user_delete_button");
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