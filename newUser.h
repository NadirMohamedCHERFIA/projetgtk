#ifndef __NEWUSER_H__
#define __NEWUSER_H__
#include "string.h"
#include "widgets.h"
#include "style.h"
#include <gtk/gtk.h>
#include "widgets.h"
#include "newUserController.h"
#include "dimensions.h"

void create_new_user(GtkWidget *butt,gpointer* data){
    MainWindow *App;
    App=(MainWindow*)data;
    // gtk_label_set_markup(GT)
    gtk_widget_hide(App->welcome_window);
    
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
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox),App->new_user_vbox_inputs,FALSE,FALSE,10);
    gtk_widget_set_name(App->new_user_vbox_inputs,"new__user__inputs__vbox");
    gtk_widget_set_size_request(App->new_user_vbox_inputs,600,600);

    //?New user description hbox
    App->new_user_description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_inputs), App->new_user_description_hbox, FALSE, FALSE, 0);
    gtk_widget_set_name(App->new_user_description_hbox,"description_hbox");
    gtk_widget_set_size_request(App->new_user_description_hbox,800,50);

    //? new user description label  
    App->new_user_description_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_description_label), "CREATE A NEW USER");
    gtk_box_pack_start(GTK_BOX(App->new_user_description_hbox), App->new_user_description_label, FALSE, FALSE, 0);

    //?new user buttons vbox
    App->new_user_vbox_buttons = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox), App->new_user_vbox_buttons, FALSE, FALSE, 0);



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
    gtk_widget_set_size_request(App->new_user_password_hbox, 30, 600); 

    //?new user password hbox confirm
    App->new_user_password_hbox_confirm = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_inputs), App->new_user_password_hbox_confirm, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_hbox, 30,600)

    //?new user password label
    App->new_user_password_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_password_label), "password ");
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_label, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_label, 300, 60);

    //?new user password input
    App->new_user_password_input = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox), App->new_user_password_input, FALSE, TRUE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(App->new_user_password_input),false);
    gtk_widget_set_size_request(App->new_user_password_input, 760, 30);

    //?new user password label confirm
    App->new_user_password_label_confirm = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->new_user_password_label_confirm), "Re-enter password ");
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox_confirm), App->new_user_password_label_confirm, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_password_label_confirm, 300, 60);

    //?new user password input confirm
    App->new_user_password_input_confirm = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->new_user_password_hbox_confirm), App->new_user_password_input_confirm, FALSE, TRUE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(App->new_user_password_input_confirm), false);
    gtk_widget_set_size_request(App->new_user_password_input_confirm, 760, 30);

    //?new user submit button
    App->new_user_submit = gtk_button_new_with_label("Submit");
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_buttons),App->new_user_submit,FALSE,FALSE,0);
    g_signal_connect(G_OBJECT(App->new_user_submit),"clicked",G_CALLBACK(handleNewUserSubmit),(gpointer)App);
    gtk_widget_set_name(App->new_user_submit,"new__user__submit");
    gtk_widget_set_size_request(App->new_user_submit, 200, 50);

    //?new user back button
    App->new_user_back = gtk_button_new_with_label("Back");
    gtk_box_pack_start(GTK_BOX(App->new_user_vbox_buttons), App->new_user_back, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->new_user_back, 400, 50);
    g_signal_connect(G_OBJECT(App->new_user_back),"clicked",G_CALLBACK(handleBack),(gpointer)App);
    gtk_widget_set_name(App->new_user_back, "new__user__back");

    gtk_widget_show_all(App->new_user_window);
}

// void create_new_user(GtkWidget *butt, gpointer *data)
// {
//     MainWindow *App;
//     App = (MainWindow *)data;
//     // gtk_label_set_markup(GT)
//     gtk_widget_hide(App->welcome_window);

//     // ?new user window
//     App->new_user_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(App->new_user_window), "Create new user");
//     gtk_window_set_position(GTK_WINDOW(App->new_user_window), GTK_WIN_POS_CENTER);
//     gtk_window_set_default_size(GTK_WINDOW(App->new_user_window), 1200, 800);
//     gtk_container_set_border_width(GTK_CONTAINER(App->new_user_window), 30);
//     gtk_widget_set_name(App->new_user_window, "new__user__window");


//     // ?new user G grid
//     App->new_user_grid = gtk_grid_new();
//     gtk_container_add(GTK_CONTAINER(App->new_user_window),App->new_user_grid);
//     gtk_widget_set_size_request(App->new_user_form_grid,(MAINWINDOWBORDERWIDTH-(2*MAINWINDOWBORDERWIDTH)),(MAINWINDOWHEIGHT-(2*MAINWINDOWBORDERWIDTH)));

//     gtk_widget_set_name(App->new_user_grid,"new_user_grid");
    
//     //? new user form grid
//     App->new_user_form_grid=gtk_grid_new();
//     gtk_grid_attach(GTK_GRID(App->new_user_grid),App->new_user_form_grid,0,0,6,1);
//     gtk_widget_set_size_request(App->new_user_form_grid, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)), ((MAINWINDOWHEIGHT - (2 * MAINWINDOWBORDERWIDTH)) * 0.66));
//     g_print("height: %f",((MAINWINDOWHEIGHT-(2*MAINWINDOWBORDERWIDTH))*0.66));
//     gtk_widget_set_name(App->new_user_form_grid,"new_user_form_grid");

//     //? new user buttons grid
//     App->new_user_buttons_grid = gtk_grid_new();
//     gtk_grid_attach(GTK_GRID(App->new_user_grid), App->new_user_buttons_grid, 0, 1,6, 1);
//     gtk_widget_set_size_request(App->new_user_buttons_grid, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)), ((MAINWINDOWHEIGHT - (2 * MAINWINDOWBORDERWIDTH)) * 0.33));
//     gtk_widget_set_name(App->new_user_buttons_grid, "new_user_buttons_grid");

//     //? new user description hbox
//     App->new_user_description_hbox=gtk_grid_new();
//     // gtk_grid_attach(GTK_CONTAINER(App->new_user_form_grid),App->new_user_description_hbox);
//     gtk_grid_attach(GTK_GRID(App->new_user_form_grid),App->new_user_description_hbox,0,0,1,1);
//     gtk_widget_set_size_request(App->new_user_description_hbox, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)), ((MAINWINDOWHEIGHT - (2 * MAINWINDOWBORDERWIDTH)) * 0.22));
//     gtk_widget_set_name(App->new_user_description_hbox,"new_user_description_box");

//     //? new_user_description label
//     App->new_user_description_label = gtk_label_new(NULL);
//     gtk_label_set_markup(GTK_LABEL(App->new_user_description_label),"Create a new user");
//     // gtk_box_pack_start(GTK_CONTAINER(App->new_user_description_hbox),App->new_user_description_label,FALSE,FALSE,0);
//     gtk_grid_attach(GTK_GRID(App->new_user_description_hbox),App->new_user_description_label,0,0,1,1);
//     gtk_widget_set_halign(App->new_user_description_label,GTK_ALIGN_CENTER);
//     gtk_widget_set_valign(App->new_user_description_label, GTK_ALIGN_CENTER);

//     gtk_widget_show_all(App->new_user_window);
// }

#endif