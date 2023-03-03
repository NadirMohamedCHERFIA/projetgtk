#include "signUp.h"

void createSignUp(GtkWidget *button,gpointer data){
    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWWIDTH  = getScreenWidth();
    gint MAINWINDOWBORDERWIDTH = 30;

    composedWindow *compApp;
    compApp = (composedWindow*)data;
    char message[100];
    strcpy(message, "Bonjour ");
    strcat(message,compApp->name);
    strcat(message," Vueillez insérer votre mot de passe afin d'accéder à votre compte");

    signUpWindow *App;
    App = g_malloc(sizeof(signUpWindow));
    //? window
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->window),"Sign up");
    gtk_window_set_default_size(GTK_WINDOW(App->window),MAINWINDOWWIDTH,MAINWINDOWHEIGHT);
    gtk_window_set_position(GTK_WINDOW(App->window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(App->window), MAINWINDOWBORDERWIDTH*5);
    gtk_widget_set_name(App->window,"signup__window");

    //? vbox
    App->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(App->window),App->vbox);
    gtk_widget_set_name(App->vbox,"signup__vbox");

    //?description hbox
    App->description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->description_hbox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->description_hbox, MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3), (MAINWINDOWHEIGHT - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.1);
    // gtk_widget_set_name(App->description_hbox,"signup__description__hbox");

    // // //? user hbox
    // App->user_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    // gtk_box_pack_start(GTK_BOX(App->vbox),App->user_hbox,TRUE,FALSE,0);
    // gtk_widget_set_size_request(App->user_hbox,MAINWINDOWWIDTH-(MAINWINDOWBORDERWIDTH*5*3),(MAINWINDOWHEIGHT-(MAINWINDOWBORDERWIDTH*5*2))*0.1);
    // gtk_widget_set_name(App->user_hbox, "signup__user__hbox");

    // //? user password
    App->password_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,100);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->password_hbox, FALSE, FALSE, 0);
    // gtk_widget_set_size_request(App->password_hbox, MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3), (MAINWINDOWHEIGHT - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.1);
    gtk_widget_set_halign(App->password_hbox,GTK_ALIGN_CENTER);
    // gtk_widget_set_name(App->password_hbox, "signup__password__hbox");

    // //? user buttons
    App->buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->buttons_hbox, TRUE, FALSE, 0);
    // gtk_widget_set_size_request(App->buttons_hbox, MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3), (MAINWINDOWHEIGHT - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.1);
    // gtk_widget_set_name(App->buttons_hbox, "signup__buttons__hbox");
    gtk_widget_set_halign(App->buttons_hbox,GTK_ALIGN_CENTER);
    
    // //?description label
    App->description_label = gtk_label_new(message);
    gtk_label_set_justify(GTK_LABEL(App->description_label),GTK_JUSTIFY_CENTER);
    gtk_label_set_xalign(GTK_LABEL(App->description_label), 0.5);
    gtk_box_pack_start(GTK_BOX(App->description_hbox),App->description_label,TRUE,TRUE,0);
    gtk_widget_set_name(App->description_label,"signup__description_label");
    // // //?user label
    // App->user_label = gtk_label_new("name:");
    // gtk_widget_set_size_request(App->user_label, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.33, 50);
    // gtk_box_pack_start(GTK_BOX(App->user_hbox),App->user_label,TRUE,FALSE,0);
    // // //?user entry
    // App->user_entry = gtk_entry_new();
    // gtk_widget_set_size_request(App->user_entry, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.64, 50);
    // gtk_box_pack_start(GTK_BOX(App->user_hbox), App->user_entry, TRUE, FALSE, 0);

    // //?password label
    App->password_label = gtk_label_new("Password :");
    // gtk_widget_set_size_request(App->password_label, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.33, 50);
    gtk_box_pack_start(GTK_BOX(App->password_hbox), App->password_label, TRUE, FALSE, 0);
    // //?password entry
    App->password_entry = gtk_entry_new();
    gtk_widget_set_size_request(App->password_entry, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.40, 50);
    gtk_box_pack_start(GTK_BOX(App->password_hbox), App->password_entry, TRUE, FALSE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(App->password_entry),FALSE);

    //? submit button
    App->submit = gtk_button_new_with_label("Valider");
    gtk_box_pack_start(GTK_BOX(App->buttons_hbox),App->submit,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->submit, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.3, 50);
    gtk_widget_set_halign(App->submit,GTK_ALIGN_CENTER);
    gtk_widget_set_name(App->cancel, "signup__submit");

    //? cancel button
    App->cancel = gtk_button_new_with_label("cancel");
    gtk_box_pack_start(GTK_BOX(App->buttons_hbox), App->cancel, FALSE, TRUE, 0);
    gtk_widget_set_size_request(App->cancel, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.3, 50);
    g_signal_connect(G_OBJECT(App->cancel),"clicked",G_CALLBACK(handleBackSignUp),(gpointer)App);
    gtk_widget_set_name(App->cancel,"signup__cancel");
    gtk_widget_show_all(App->window);
}
void handleBackSignUp (GtkWidget *butt,gpointer data){
    signUpWindow *App;
    App = (signUpWindow*)data;
    gtk_window_close(GTK_WINDOW(App->window));
    }

