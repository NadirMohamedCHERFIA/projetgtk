#include <gtk/gtk.h>
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
struct _MainWindow
{   
    //welcom widgets
    GtkWidget *welcome_window;
    GtkWidget *welcome_vbox;
    GtkWidget *welcome_vbox_users;
    GtkWidget *welcome_vbox_buttons;
    GtkWidget *welcome_new_user_button;
    GtkWidget *welcome_quit;
    //new user
    GtkWidget *new_user_window;
    GtkWidget *new_user_vbox;
    GtkWidget *new_user_vbox_inputs;
    GtkWidget *new_user_vbox_buttons;
    GtkWidget *new_user_submit;
    GtkWidget *new_user_back;
    GtkWidget *new_user_username_hbox;
    GtkWidget *new_user_username_label;
    GtkWidget *new_user_username_input;
    GtkWidget *new_user_password_hbox;
    GtkWidget *new_user_password_label;
    GtkWidget *new_user_password_input;
};
typedef struct _MainWindow MainWindow;

#endif