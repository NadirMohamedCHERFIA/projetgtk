#include <gtk/gtk.h>
#include "string.h"
#include "deleteConfirmForm.h"
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
    GtkWidget *dashboard_depenses_modify_button;
    GtkWidget *dashboard_income_modify_button;

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
typedef struct
{
    char name[100];
    char password[100];
    GtkWidget *window;
} userNamePassword;
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
    //delete user info
};
typedef struct _MainWindow MainWindow;

typedef struct {
    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *button;
    GtkWidget *box;
}imageWindow;

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

typedef struct{

    GtkWindow *window;
    GtkWindow *vbox;
    GtkWidget *descriptionbox;
    GtkWidget *descriptionlabel;
    GtkWidget *income_type_box;
    GtkWidget *typeLabel;
    GtkWidget *income_monthly_radio;
    GtkWidget *income_not_monthly_radio;

    //?*************************************
    gint selected_type;
    //?**********************************
    GtkWidget *valuebox;
    GtkWidget *valueEntry;
    GtkWidget *valueLabel;
    //******************************************
    GtkWidget *databox;
    GtkWidget *modifyButton;
    GtkWidget *dateLabel;
    //***********************************************
    GtkWidget *valueDescriptionBox;
    GtkWidget *valueDescriptionLabel;
    GtkTextView *valueDescriptionEntry;
    GtkWidget *textViewScrolledWindow;
    //******************************************
    GtkWidget *buttonsbox;
    GtkWidget *confirmButton;
    GtkWidget *cancelButton;

}incomeAddWindow;

typedef struct
{

    GtkWindow *window;
    GtkWindow *vbox;
    GtkWidget *descriptionbox;
    GtkWidget *descriptionlabel;
    GtkWidget *depense_type_box;
    GtkWidget *typeLabel;
    GtkWidget *scrolledWindow;
    GtkWidget *typelabelbox;
    //?*************************
    GtkWidget *logement_radio;
    GtkWidget *quotidienne_radio;
    GtkWidget *loisirs_radio;
    GtkWidget *voyages_et_transports;
    GtkWidget *abonnemets;
    GtkWidget *auto_moto;
    GtkWidget *sante;
    GtkWidget *alimentation;
    GtkWidget *vacances;
    GtkWidget *Animeaux;
    GtkWidget *depensesTypes[10];
    //?*************************************
    gint selected_type;
    //?**********************************
    GtkWidget *valuebox;
    GtkWidget *valueEntry;
    GtkWidget *valueLabel;
    //******************************************
    GtkWidget *databox;
    GtkWidget *modifyButton;
    GtkWidget *dateLabel;
    //***********************************************
    GtkWidget *valueDescriptionBox;
    GtkWidget *valueDescriptionLabel;
    GtkTextView *valueDescriptionEntry;
    GtkWidget *textViewScrolledWindow;
    //******************************************
    GtkWidget *buttonsbox;
    GtkWidget *confirmButton;
    GtkWidget *cancelButton;

} depenseAddWindow;

typedef struct {
    GtkWidget *calendar;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    char date_string[100];
    char date_formated[100];
}calendarWindow;

typedef struct
{
    float value;
    char category[10];
    char description[1000];
    char date[20];
} detail_row;

typedef struct {

    gchar date_string[100];
    gchar date_formated[100];
    gint nbr_rows;
    // char income_details[50][1000];

    detail_row income_details[100];
    // income_details = malloc(100*sizeof(detail_row));
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *descriptionBox;
    GtkWidget *descriptionLabel;
    GtkWidget *scrolledWindow;
    GtkWidget *detailsBox;
    GtkWidget *detailsRowBox;
    GtkWidget *byDay;
    GtkWidget *byMonth;
    GtkWidget *info_row_box[100];
    GtkWidget *info_row_label[100];


    //*************************
    GtkWidget *headerDesc;
    GtkWidget *header_valueBox;
    GtkWidget *header_valueBox_label;
    GtkWidget *header_categoryBox;
    GtkWidget *header_categoryBox_label;

    GtkWidget *header_dateBox;
    GtkWidget *header_dateBox_label;

    GtkWidget *header_descriptionBox;
    GtkWidget *header_descriptionBox_label;

}incomeDetailsWindow;

typedef struct
{

    gchar date_string[100];
    gchar date_formated[100];
    gint nbr_rows;
    // char income_details[50][1000];

    detail_row depenses_details[100];
    // income_details = malloc(100*sizeof(detail_row));
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *descriptionBox;
    GtkWidget *descriptionLabel;
    GtkWidget *scrolledWindow;
    GtkWidget *detailsBox;
    GtkWidget *detailsRowBox;
    GtkWidget *byDay;
    GtkWidget *byMonth;
    GtkWidget *info_row_box[100];
    GtkWidget *info_row_label[100];

    //*************************
    GtkWidget *headerDesc;
    GtkWidget *header_valueBox;
    GtkWidget *header_valueBox_label;
    GtkWidget *header_categoryBox;
    GtkWidget *header_categoryBox_label;

    GtkWidget *header_dateBox;
    GtkWidget *header_dateBox_label;

    GtkWidget *header_descriptionBox;
    GtkWidget *header_descriptionBox_label;

} depenseDetailsWindow;

#endif