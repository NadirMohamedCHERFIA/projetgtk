#include "dashboard.h"

char MONTHS[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Décembre"};

void handleBackDashboard(GtkWidget *butt, gpointer data)
{
    composedWindow *compApp;
    compApp = (composedWindow *)data;
    gtk_window_close(GTK_WINDOW(compApp->dashboard->dashboard_window));
    gtk_widget_show_all(compApp->App->welcome_vbox_users); 
    gtk_widget_show_all(compApp->App->welcome_window);
}

static void onCalendarChange(GtkWidget *calendar,gpointer data){
    composedWindow *compApp = (composedWindow*)data;
    guint year, month, day;
    gtk_calendar_get_date(calendar, &year, &month, &day);

    sprintf(compApp->date_formated,"%d-%02d",year,month+1);
    sprintf(compApp->date_string,"%02d %s %d",day, MONTHS[month],year);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_date_label),compApp->date_string);
    get_total_depenses_and_income((gpointer)compApp);
    char depenses[100];
    sprintf(depenses, "Les depenses totales de ce mois \n\n %.2lf €", compApp->total_depenses);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_total_depenses_label),depenses);
    char income[100];
    sprintf(income, "Le revenue total de ce mois \n\n %.2lf €", compApp->total_income);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_total_income_label), income);
    char economy[100];
    sprintf(economy, "L'economie de ce mois \n\n %.2lf €", compApp->total_income - compApp->total_depenses);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_economy_label), economy);
}

    void
    create_dashboard(gpointer data)
{
    composedWindow *compApp ;
    compApp= (composedWindow *)data;

    gint MAINWINDOWWIDTH = getScreenWidth();

    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWBORDERWIDTH = 30;
    char message[100];
    strcpy(message,"Bonjour ");
    strcat(message,compApp->name);
    g_print("dashboard id:%d",compApp->id);
    //? dashboard window
    dashboardWindow *App= g_malloc(sizeof(dashboardWindow));
    // gtk_widget_hide(compApp->App->welcome_window);
    App->dashboard_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->dashboard_window), "Dasboard");
    gtk_window_set_default_size(GTK_WINDOW(App->dashboard_window), MAINWINDOWWIDTH, MAINWINDOWHEIGHT);
    gtk_window_set_position(GTK_WINDOW(App->dashboard_window), GTK_WIN_POS_CENTER);
    gtk_widget_set_name(App->dashboard_window, "dashboard_window");
    gtk_container_set_border_width(GTK_CONTAINER(App->dashboard_window), MAINWINDOWBORDERWIDTH);
    compApp->dashboard=App;
    
    // get_total_depenses_and_income((gpointer)compApp);

    //?dashboard vbox
    App->dashboard_vbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(App->dashboard_window), App->dashboard_vbox);
    gtk_widget_set_name(App->dashboard_vbox, "dashboard__vbox");

    //? dashboard left vbox
    App->dashboard_left_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
    gtk_box_pack_start(GTK_BOX(App->dashboard_vbox), App->dashboard_left_vbox, FALSE, TRUE, 0);

    //? dashboard date box
    App->dashboard_date_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox),App->dashboard_date_box,FALSE,TRUE,0);
    gtk_widget_set_name(App->dashboard_date_box,"date__box");

    //? dashboard date label
    App->dashboard_date_label = gtk_label_new(compApp->date_string);
    gtk_box_pack_start(GTK_BOX(App->dashboard_date_box),App->dashboard_date_label,TRUE,TRUE,0);

    //? dashboard right vbox
    App->dashboard_right_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_vbox), App->dashboard_right_vbox, TRUE, TRUE, 0);

    //? dashboard calendar
    App->dashboard_calendar = gtk_calendar_new();
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox), App->dashboard_calendar, TRUE, TRUE, 0);
    // gtk_widget_set_size_request(App->dashboard_calendar, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)) * 0.33, (MAINWINDOWHEIGHT - (2 * MAINWINDOWBORDERWIDTH)) * 0.5);


    //? dashboard selected user hbox
    App->dashboard_selected_user_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_right_vbox), App->dashboard_selected_user_hbox, FALSE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_selected_user_hbox, "selected_user_hbox");
    gtk_widget_set_halign(App->dashboard_selected_user_hbox,GTK_ALIGN_CENTER);

    //? dashboard selected user label
    App->dashboard_selected_user_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(App->dashboard_selected_user_label), message);
    gtk_box_pack_start(GTK_BOX(App->dashboard_selected_user_hbox), App->dashboard_selected_user_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(App->dashboard_selected_user_hbox,100,100);
    gtk_label_set_justify(GTK_LABEL(App->dashboard_selected_user_label),GTK_JUSTIFY_CENTER);
    gtk_label_set_xalign(GTK_LABEL(App->dashboard_selected_user_label),0.5);


    //? left vbox buttons vbox
    App->dashboard_left_vbox_buttons_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox), App->dashboard_left_vbox_buttons_vbox, FALSE, TRUE, 0);

    //? dashboard configure button
    App->dashboard_configure_button = gtk_button_new_with_label("Configurer le budget de ce mois");
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox),App->dashboard_configure_button,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->dashboard_configure_button, 100, 60);

    //? dashboard show details button
    App->dashboard_show_details_button = gtk_button_new_with_label("Show details");
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox_buttons_vbox), App->dashboard_show_details_button, FALSE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_show_details_button, "dashboard__details_button");
    gtk_widget_set_size_request(App->dashboard_show_details_button, 100, 60);


    //? dashboard back button
    App->dashboard_back_button = gtk_button_new_with_label("Back");
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox_buttons_vbox), App->dashboard_back_button, FALSE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_back_button, "dashboard__back_button");
    gtk_widget_set_size_request(App->dashboard_back_button, 100, 60);
    g_signal_connect(G_OBJECT(App->dashboard_back_button), "clicked", G_CALLBACK(handleBackDashboard), (gpointer) compApp);




    //! ---------------------------------------------------------------------------------------------------------------------------------

    //? dashboard income and depenses box
    App->dashboard_solde_info_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,30);
    gtk_box_pack_start(GTK_BOX(App->dashboard_right_vbox),App->dashboard_solde_info_hbox,TRUE,TRUE,0);
    gtk_widget_set_name(App->dashboard_solde_info_hbox,"info__solde__hbox");
    gtk_container_set_border_width(GTK_CONTAINER(App->dashboard_solde_info_hbox), 50);

    //? dashboard total income box
    App->dashboard_total_income_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_solde_info_hbox),App->dashboard_total_income_vbox,TRUE,TRUE,0);
    gtk_widget_set_name(App->dashboard_total_income_vbox,"total__income__box");

    //? total income label
    App->dashboard_total_income_label = gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(App->dashboard_total_income_vbox),App->dashboard_total_income_label,TRUE,TRUE,0);

    //? income buttons box
    App->dashbord_income_button_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_total_income_vbox),App->dashbord_income_button_hbox,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->dashbord_income_button_hbox,100,100);

    //? income detail button
    App->dashboard_income_detail_button = gtk_button_new_with_label("Details");
    gtk_box_pack_start(GTK_BOX(App->dashbord_income_button_hbox), App->dashboard_income_detail_button, TRUE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_income_detail_button,"income__detail");

    //? income ajoute button 
    App->dashboard_income_ajoute_button = gtk_button_new_with_label("Ajouter");
    gtk_box_pack_start(GTK_BOX(App->dashbord_income_button_hbox),App->dashboard_income_ajoute_button,TRUE,TRUE,0);


    //? dashboard total depenses box 
    App->dashboard_total_depenses_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_solde_info_hbox), App->dashboard_total_depenses_vbox, TRUE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_total_depenses_vbox, "total__depenses__box");

    //? total depenses label

    App->dashboard_total_depenses_label = gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(App->dashboard_total_depenses_vbox), App->dashboard_total_depenses_label, TRUE, TRUE, 0);

    //? depenses buttons box
    App->dashbord_depenses_button_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_total_depenses_vbox),App->dashbord_depenses_button_hbox,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->dashbord_depenses_button_hbox,100,100);

    //? depenses detail button
    App->dashboard_depenses_detail_button = gtk_button_new_with_label("Details");
    gtk_box_pack_start(GTK_BOX(App->dashbord_depenses_button_hbox), App->dashboard_depenses_detail_button, TRUE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_depenses_detail_button, "depenses__detail");

    //? depenses ajoute button
    App->dashboard_depenses_ajoute_button = gtk_button_new_with_label("Ajouter");
    gtk_box_pack_start(GTK_BOX(App->dashbord_depenses_button_hbox), App->dashboard_depenses_ajoute_button, TRUE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_depenses_ajoute_button, "depenses__ajoute");

    //? dashboard categories scrolled window
    App->dashboard_categories_scrolled_window = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(App->dashboard_categories_scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    // gtk_container_add(GTK_CONTAINER(App->dashboard_right_vbox),App->dashboard_categories_scrolled_window);
    gtk_box_pack_start(GTK_BOX(App->dashboard_right_vbox),App->dashboard_categories_scrolled_window,TRUE,TRUE,0);
    gtk_widget_show_all(App->dashboard_categories_scrolled_window);

    //? dashboard economy box
    App->dashboard_economy_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_solde_info_hbox), App->dashboard_economy_vbox, TRUE, TRUE, 0);
    gtk_widget_set_name(App->dashboard_economy_vbox, "economy__box");

    //? dashboard economy label
    App->dashboard_economy_label = gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(App->dashboard_economy_vbox),App->dashboard_economy_label,TRUE,TRUE,0);


    //? dashboard categories box
    App->dashboard_categories_hbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // gtk_box_pack_start(GTK_BOX(App->dashboard_right_vbox),App->dashboard_categories_hbox,TRUE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(App->dashboard_categories_scrolled_window),App->dashboard_categories_hbox);
    gtk_widget_set_name(App->dashboard_categories_hbox, "info__categories__hbox");
    gtk_container_set_border_width(GTK_CONTAINER(App->dashboard_categories_hbox),50);


    //? handle date change
    g_signal_connect(G_OBJECT(App->dashboard_calendar), "day-selected", G_CALLBACK(onCalendarChange), (gpointer)compApp);
    onCalendarChange(App->dashboard_calendar, (gpointer)compApp);

    gtk_widget_show_all(App->dashboard_window);
}

