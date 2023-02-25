#ifndef __NEWUSER_H__
#define __NEWUSER_H__
#include "string.h"
#include "widgets.h"
#include "style.h"
#include <gtk/gtk.h>
#include "widgets.h"
#include "newUserController.h"

void create_new_user(GtkWidget *butt,gpointer data){
    MainWindow *App;

    // ?new user window
    App->new_user_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->new_user_window),"Create new user");
    gtk_window_set_position(GTK_WINDOW(App->new_user_window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(App->new_user_window),1200,800);
    gtk_container_set_border_width(GTK_CONTAINER(App->new_user_window),30);
    gtk_widget_set_name(App->new_user_window,"new__user__window");

    //?new user G vbox
    App->new_user_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
    gtk_container_add(GTK_CONTAINER(App->new_user_window),App->new_user_vbox);

    //? new user inputs vbox
    App->new_user_vbox_inputs = gtk_box_new(GTK_ORIENTATION_VERTICAL,50);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox),App->new_user_vbox_inputs,FALSE,FALSE,0);
    gtk_widget_set_name(App->new_user_vbox_inputs,"new__user__inputs__vbox");
    gtk_widget_set_size_request(App->new_user_vbox_inputs,600,600);

    //?new user buttons vbox
    App->new_user_vbox_buttons = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_vbox_buttons, FALSE, TRUE, 0);

    //?new user username hbox
    App->new_user_username_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_inputs),App->new_user_username_hbox,FALSE,TRUE,0);

    //? new user username label
    App->new_user_username_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_username_label),"Username ");
    gtk_box_pack_start(GTK_BOX(App->new_user_username_hbox),App->new_user_username_label,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->new_user_username_label, 300, 30);

    //?new user username input
    App->new_user_username_input = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_username_hbox),App->new_user_username_input,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->new_user_username_input, 760, 60);

    //?new user password hbox
    App->new_user_password_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_inputs), App->new_user_password_hbox, FALSE, TRUE, 0);
    // gtk_widget_set_size_request(App->new_user_password_hbox, 30, 600);

    //?new user password label
    App->new_user_password_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_password_label), "password ");
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_label, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_label, 300, 60);

    //?new user password input
    App->new_user_password_input = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_input, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_input, 760, 30);

    //?new user submit button
    App->new_user_submit = gtk_button_new_with_label("Submit");
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_buttons),App->new_user_submit,FALSE,FALSE,0);
    g_signal_connect(G_OBJECT(App->new_user_submit),"clicked",G_CALLBACK(handleNewUserSubmit),(gpointer) App);
    gtk_widget_set_name(App->new_user_submit,"new__user__submit");
    gtk_widget_set_size_request(App->new_user_submit, 200, 50);

    //?new user back button
    App->new_user_back = gtk_button_new_with_label("Back");
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_buttons), App->new_user_back, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_back, 400, 50);
    g_signal_connect(G_OBJECT(App->new_user_back),"clicked",G_CALLBACK(handleBack),(gpointer) App);
    gtk_widget_set_name(App->new_user_back, "new__user__back");

    gtk_widget_show_all(App->new_user_window);
}


#endif