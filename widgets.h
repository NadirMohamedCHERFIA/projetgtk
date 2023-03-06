#include <gtk/gtk.h>
#include "string.h"
#ifndef __CONTAINER_H__
#define __CONTAINER_H__

typedef struct{
    // Gtk dashboard
    gint *dashboard_chosed_user_id;
    GtkWidget *dashboard_window;
    GtkWidget *dashboard_vbox;
    GtkWidget *dashboard_left_vbox;
    GtkWidget *dashboard_right_vbox;
    GtkWidget *dashboard_calendar;
    GtkWidget *dashboard_selected_user_hbox;
    GtkWidget *dashboard_selected_user_label;
    GtkWidget *dashboard_back_button;
    GtkWidget *dashboard_show_details_button;
    GtkWidget *dashboard_left_vbox_buttons_vbox;
    GtkWidget *dashboard_configure_button;
    //selected date
    GtkWidget *dashboard_date_box;
    GtkWidget *dashboard_date_label;
    // related to soldde
    GtkWidget *dashboard_solde_info_hbox;
    GtkWidget *dashboard_total_income_vbox;
    GtkWidget *dashboard_total_depenses_vbox;
    GtkWidget *dashboard_total_income_label;
    GtkWidget *dashboard_total_depenses_label;
    GtkWidget *dashboard_depenses_detail_button;
    GtkWidget *dashboard_income_detail_button;
    GtkWidget *dashboard_economy_vbox;
    GtkWidget *dashboard_economy_label;
    GtkWidget *dashbord_income_button_hbox;

    GtkWidget *dashboard_income_ajoute_button;
    GtkWidget *dashbord_depenses_button_hbox;
    GtkWidget *dashboard_depenses_ajoute_button;
    // related to categories
    GtkWidget *dashboard_categories_hbox;
    GtkWidget *dashboard_categories_scrolled_window;

}dashboardWindow;

typedef struct{
    GtkWidget *new_user_window;
    GtkWidget *new_user_grid;
    GtkWidget *new_user_form_grid;
    GtkWidget *new_user_buttons_grid;
    GtkWidget *new_user_vbox;
    GtkWidget *new_user_vbox_inputs;
    GtkWidget *new_user_hbox_buttons;
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
}newUserWindow;

struct _MainWindow
{   
    int numberOfUsers;

    // new user creation
    GtkWidget *user_label[100];
    GtkWidget *users_hbox[100];
    GtkWidget *user_delete_button[100];
    GtkWidget *user_select_button[100];
    char users[100][255];

    //welcom widgets
    GtkWidget *welcome_window;
    GtkWidget *welcome_vbox;
    GtkWidget *welcome_description_hbox;
    GtkWidget *welcome_description_label;
    GtkWidget *welcome_vbox_users;
    GtkWidget *welcome_hbox_buttons;
    GtkWidget *welcome_new_user_button;
    GtkWidget *welcome_quit;
    GtkWidget *welcome_users_scrolled_window;
    //new user

};
typedef struct _MainWindow MainWindow;

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *user_hbox;
    GtkWidget *password_hbox;
    GtkWidget *description_hbox;
    GtkWidget *buttons_hbox;
    GtkWidget *description_label;
    GtkWidget *user_label;
    GtkWidget *user_entry;
    GtkWidget *password_label;
    GtkWidget *password_entry;
    GtkWidget *submit;
    GtkWidget *cancel;
}signUpWindow;

#endif