#include "welcome.h"
void show_window(gpointer data){
    composedWindow *compApp = (composedWindow*)data;
    compApp->first_load =0;
    MainWindow *App;
    App= compApp->App;
    gtk_widget_show_all(App->welcome_users_scrolled_window);
    gtk_widget_show_all(App->welcome_window);
}
int welcome_window(gpointer data)
{
    const gchar *const WELCOMEWINDOWTITLE = "GESTION DE DEPENSES";

    composedWindow *compApp = (composedWindow *)data;
    MainWindow *App ;
    App = compApp->App;
    // userNamePassword *user = g_malloc(sizeof(userNamePassword));
    // compApp->userDelteConfirmation = user;
    //? initialising the number of users and then sending a request to get it
    App->numberOfUsers = 0;
    gint MAINWINDOWWIDTH = getScreenWidth();
    gint MAINWINDOWHEIGHT =getScreenHeight();
    gint MAINWINDOWBORDERWIDTH =30;

    //?Welcome window
    App->welcome_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // gtk_window_set_title(GTK_WINDOW(App->welcome_window), WELCOMEWINDOWTITLE);
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar),"GESTION DE DEPENSES");
    gtk_window_set_titlebar(GTK_WINDOW(App->welcome_window),titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar,"titleBar");

    gtk_window_set_default_size(GTK_WINDOW(App->welcome_window), MAINWINDOWWIDTH, MAINWINDOWHEIGHT);
    // gtk_window_fullscreen(App->welcome_window);
    g_signal_connect(GTK_WINDOW(App->welcome_window), "destroy", G_CALLBACK(onQuitButton), (gpointer)App);
    gtk_window_set_position(GTK_WINDOW(App->welcome_window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(App->welcome_window), MAINWINDOWBORDERWIDTH);
    gtk_widget_set_name(App->welcome_window, "main__window");
    // compApp->App = App;
    get_users((gpointer)compApp);
    // gtk_widget_hide(App->welcome_window);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // GtkWidget *overlay;
    // overlay = gtk_overlay_new();
    // gtk_container_add(GTK_CONTAINER(App->welcome_window),overlay);
    // gtk_overlay_add_overlay(GTK_OVERLAY(overlay),image);
    // GtkWidget *image;
    // image=gtk_image_new_from_file("background.png");
    // gtk_container_add(GTK_CONTAINER(App->welcome_window),image);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //? welcome scrollable window
    App->welcome_users_scrolled_window = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(App->welcome_users_scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    //? welcome wrapper vbox
    App->welcome_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(App->welcome_window), App->welcome_vbox);

    //? welcome description hbox
    App->welcome_description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox),App->welcome_description_hbox,TRUE,TRUE,0);
    gtk_widget_set_halign(App->welcome_description_hbox,GTK_ALIGN_CENTER);

    //? welcome description label
    App->welcome_description_label = gtk_label_new("Contr??le des d??penses");
    gtk_box_pack_start(GTK_BOX(App->welcome_description_hbox),App->welcome_description_label,FALSE,FALSE,0);
    gtk_label_set_justify(GTK_LABEL(App->welcome_description_label),GTK_JUSTIFY_CENTER);
    gtk_widget_set_name(App->welcome_description_label,"welcome_description_label");

    //?users vertical box
    App->welcome_vbox_users = gtk_box_new(GTK_ORIENTATION_VERTICAL,50);
    gtk_widget_set_name(App->welcome_vbox_users, "users__vbox");
    handle_users((gpointer)App);
    gtk_widget_set_name(App->welcome_vbox_users, "users_vbox");
    // gtk_box_pack_start(GTK_BOX(App->welcome_vbox), App->welcome_vbox_users, TRUE, FALSE, 0);
    gtk_widget_set_name(App->welcome_users_scrolled_window,"TEST");
    gtk_container_add(GTK_CONTAINER(App->welcome_users_scrolled_window),App->welcome_vbox_users);
    gtk_container_add(GTK_CONTAINER(App->welcome_vbox),App->welcome_users_scrolled_window);
    gtk_container_set_border_width(GTK_CONTAINER(App->welcome_users_scrolled_window),50);
    gtk_widget_set_size_request(App->welcome_users_scrolled_window,MAINWINDOWWIDTH-(MAINWINDOWBORDERWIDTH*5*2),600);

    //?buttons hertical box 
    App->welcome_hbox_buttons = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox), App->welcome_hbox_buttons,TRUE, TRUE, 0);
    gtk_widget_set_name(App->welcome_hbox_buttons, "buttons__vbox");

    //?Adding user button
    App->welcome_new_user_button = gtk_button_new_with_label("Ajouet un nouveau utilisateur");
    gtk_box_pack_start(GTK_BOX(App->welcome_hbox_buttons), App->welcome_new_user_button, TRUE, TRUE, 40);
    gtk_widget_set_name(App->welcome_new_user_button, "add__user__button");
    g_signal_connect(G_OBJECT(App->welcome_new_user_button), "clicked", G_CALLBACK(create_new_user), (gpointer)compApp);

    //?welcome quit
    App->welcome_quit = gtk_button_new_with_label("Exit");
    gtk_box_pack_start(GTK_BOX(App->welcome_hbox_buttons), App->welcome_quit, TRUE, TRUE, 40);
    g_signal_connect(GTK_BUTTON(App->welcome_quit), "clicked", G_CALLBACK(onQuitButton), (gpointer)data);
    gtk_widget_set_name(App->welcome_quit, "quit__button");
    gtk_widget_show_all(App->welcome_users_scrolled_window);
    gtk_widget_show_all(App->welcome_window);

}