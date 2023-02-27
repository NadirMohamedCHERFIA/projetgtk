#include <gtk/gtk.h>
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
struct _MainWindow
{   
    int numberOfUsers;

    // GtkWidget *user_hbox[numberOfUsers];
    GtkWidget *user_label[100];
    GtkWidget *users_hbox[100];
    char users[100][255];
    //welcom widgets
    GtkWidget *welcome_window;
    GtkWidget *welcome_vbox;
    GtkWidget *welcome_vbox_users;
    GtkWidget *welcome_vbox_buttons;
    GtkWidget *welcome_new_user_button;
    GtkWidget *welcome_quit;
    GtkWidget *welcome_users_scrolled_window;
    //new user
    GtkWidget *new_user_window;
    GtkWidget *new_user_grid;
    GtkWidget *new_user_form_grid;
    GtkWidget *new_user_buttons_grid;
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
    GtkWidget *new_user_password_hbox_confirm;
    GtkWidget *new_user_password_label_confirm;
    GtkWidget *new_user_description_hbox;
    GtkWidget *new_user_description_label;

    GtkWidget *new_user_password_input_confirm;
};
typedef struct _MainWindow MainWindow;

#endif