#include "newUser.h"

void create_new_user(GtkWidget *butt, gpointer data)
{
    composedWindow *compApp=(composedWindow *)data;
    // MainWindow *App;
    // App = compApp->App;
    newUserWindow *App;
    App = compApp->newUser;
    gtk_widget_hide(compApp->App->welcome_window);
    gint MAINWINDOWWIDTH = getScreenWidth();
    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWBORDERWIDTH = 30;

    // ?new user window
    App->new_user_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->new_user_window), "Creation d'un nouveau utilisateur");
    gtk_window_set_position(GTK_WINDOW(App->new_user_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(App->new_user_window), MAINWINDOWWIDTH,MAINWINDOWHEIGHT);
    gtk_container_set_border_width(GTK_CONTAINER(App->new_user_window),MAINWINDOWBORDERWIDTH*5);
    gtk_widget_set_name(App->new_user_window, "new__user__window");
    compApp->newUser = App;

    //?new user G vbox
    App->new_user_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(App->new_user_window), App->new_user_vbox);
    gtk_widget_set_name(App->new_user_vbox,"new_user_vbox");

    //?New user description hbox
    App->new_user_description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_description_hbox, TRUE, TRUE, 0);
    gtk_widget_set_name(App->new_user_description_hbox,"description_hbox");


    //?new user username hbox
    App->new_user_username_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_username_hbox, TRUE, FALSE, 0);
    gtk_widget_set_halign(App->new_user_username_hbox,GTK_ALIGN_CENTER);

    // //?new user password hbox
    App->new_user_password_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_password_hbox, TRUE, FALSE, 0);
    gtk_widget_set_halign(App->new_user_password_hbox, GTK_ALIGN_CENTER);

    // //?new user password hbox confirm
    App->new_user_password_hbox_confirm = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_password_hbox_confirm, TRUE, FALSE, 0);
    gtk_widget_set_halign(App->new_user_password_hbox_confirm, GTK_ALIGN_CENTER);

    //? new user buttons hbox
    App->new_user_hbox_buttons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,50);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox),App->new_user_hbox_buttons,TRUE,FALSE,0);
    gtk_widget_set_halign(App->new_user_hbox_buttons,GTK_ALIGN_CENTER);

    //? new user description label
    App->new_user_description_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_description_label), "Creation d'un nouveau utilisateur");
    gtk_box_pack_start(GTK_BOX(App->new_user_description_hbox), App->new_user_description_label, TRUE, TRUE, 0);
    gtk_label_set_justify(GTK_LABEL(App->new_user_description_label),GTK_JUSTIFY_CENTER);
    gtk_label_set_xalign(GTK_LABEL(App->new_user_description_label),0.5);
    gtk_widget_set_name(App->new_user_description_label,"new_user_description_label");

    // //? new user username label
    App->new_user_username_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_username_label), "name : ");
    gtk_box_pack_start(GTK_BOX(App->new_user_username_hbox), App->new_user_username_label, TRUE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_username_label, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.30, 50);

    // //?new user username input
    App->new_user_username_input = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_username_hbox), App->new_user_username_input, FALSE, FALSE, 0);
    gtk_widget_set_size_request(App->new_user_username_input, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.40, 50);





    // //?new user password label
    App->new_user_password_label = gtk_label_new("Mot de passe : ");
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_label, TRUE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_label, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.30, 50);

    // //?new user password input
    App->new_user_password_input = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_input, FALSE, TRUE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(App->new_user_password_input), false);
    gtk_widget_set_size_request(App->new_user_password_input, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.40, 50);

    // //?new user password label confirm
    App->new_user_password_label_confirm = gtk_label_new(" Re-entrer le mot de passe : ");
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox_confirm), App->new_user_password_label_confirm, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->new_user_password_label_confirm, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.30, 50);

    // //?new user password input confirm
    App->new_user_password_input_confirm = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox_confirm), App->new_user_password_input_confirm, FALSE, TRUE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(App->new_user_password_input_confirm), false);
    gtk_widget_set_size_request(App->new_user_password_input_confirm, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.40, 50);
    g_signal_connect(G_OBJECT(App->new_user_password_input_confirm), "activate", G_CALLBACK(handleNewUserSubmit), (gpointer)compApp);

    // //?new user submit button
    App->new_user_submit = gtk_button_new_with_label("Submit");
    gtk_box_pack_start(GTK_BOX(App->new_user_hbox_buttons), App->new_user_submit, FALSE, TRUE, 0);
    g_signal_connect(G_OBJECT(App->new_user_submit), "clicked", G_CALLBACK(handleNewUserSubmit), (gpointer)compApp);
    gtk_widget_set_name(App->new_user_submit, "new__user__submit");
    gtk_widget_set_halign(App->new_user_submit,GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(App->new_user_submit, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.4, 50);

    // //?new user back button
    App->new_user_back = gtk_button_new_with_label("Back");
    gtk_box_pack_start(GTK_BOX(App->new_user_hbox_buttons), App->new_user_back, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_back, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.4, 50);
    g_signal_connect(G_OBJECT(App->new_user_back), "clicked", G_CALLBACK(handleBack), (gpointer)compApp);
    gtk_widget_set_name(App->new_user_back, "new__user__back");

    gtk_widget_show_all(App->new_user_window);
}
