#include "dashboard.h"

void handleBackDashboard(GtkWidget *butt, gpointer data)
{
    composedWindow *compApp;
    compApp = (composedWindow *)data;
    gtk_window_close(GTK_WINDOW(compApp->dashboard->dashboard_window));
    gtk_widget_show_all(compApp->App->welcome_window); 
}

void create_dashboard(gpointer data)
{
    composedWindow *compApp ;
    compApp= (composedWindow *)data;
    gint MAINWINDOWWIDTH = getScreenWidth();
    // gint MAINWINDOWWIDTH = 1200;

    gint MAINWINDOWHEIGHT = getScreenHeight();
    // gint MAINWINDOWHEIGHT = 800;
    gint MAINWINDOWBORDERWIDTH = 30;
    char message[100];
    strcpy(message,"Bonjour ");
    strcat(message,compApp->name);
    // g_print("\ndashboard : %s",composedwindow->name);
    g_print("dashboard id:%d",compApp->id);
    //? dashboard window
    dashboardWindow *App= g_malloc(sizeof(dashboardWindow));
    gtk_widget_hide(compApp->App->welcome_window);
    App->dashboard_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->dashboard_window), "Dasboard");
    gtk_window_set_default_size(GTK_WINDOW(App->dashboard_window), MAINWINDOWWIDTH, MAINWINDOWHEIGHT);
    gtk_window_set_position(GTK_WINDOW(App->dashboard_window), GTK_WIN_POS_CENTER);
    gtk_widget_set_name(App->dashboard_window, "dashboard_window");
    gtk_container_set_border_width(GTK_CONTAINER(App->dashboard_window), MAINWINDOWBORDERWIDTH);
    compApp->dashboard=App;

    //?dashboard vbox
    App->dashboard_vbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(App->dashboard_window), App->dashboard_vbox);
    gtk_widget_set_name(App->dashboard_vbox, "dashboard__vbox");

    //? dashboard left vbox
    App->dashboard_left_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
    gtk_box_pack_start(GTK_BOX(App->dashboard_vbox), App->dashboard_left_vbox, FALSE, TRUE, 0);
    // gtk_widget_set_size_request(App->dashboard_left_vbox, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)) * 0.3, MAINWINDOWHEIGHT - (2* MAINWINDOWBORDERWIDTH));

    //? dashboard right vbox
    App->dashboard_right_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->dashboard_vbox), App->dashboard_right_vbox, TRUE, TRUE, 0);
    // gtk_widget_set_size_request(App->dashboard_right_vbox, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)) * 0.6, MAINWINDOWHEIGHT - (2*MAINWINDOWBORDERWIDTH));

    //? dashboard calendar
    App->dashboard_calendar = gtk_calendar_new();
    gtk_box_pack_start(GTK_BOX(App->dashboard_left_vbox), App->dashboard_calendar, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->dashboard_calendar, (MAINWINDOWWIDTH - (2 * MAINWINDOWBORDERWIDTH)) * 0.33, (MAINWINDOWHEIGHT - (2 * MAINWINDOWBORDERWIDTH)) * 0.5);

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

    gtk_widget_show_all(App->dashboard_window);
}

