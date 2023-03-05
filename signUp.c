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
    compApp->dashboard = App;
    //? vbox
    App->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(App->window),App->vbox);
    gtk_widget_set_name(App->vbox,"signup__vbox");

    //?description hbox
    App->description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->description_hbox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->description_hbox, MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3), (MAINWINDOWHEIGHT - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.1);
    gtk_widget_set_name(App->description_hbox,"signup__description__hbox"); 
    // //? user password
    App->password_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,100);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->password_hbox, FALSE, FALSE, 0);
    gtk_widget_set_halign(App->password_hbox,GTK_ALIGN_CENTER);

    // //? user buttons
    App->buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(App->vbox), App->buttons_hbox, TRUE, FALSE, 0);
    gtk_widget_set_halign(App->buttons_hbox,GTK_ALIGN_CENTER);
    
    // //?description label
    App->description_label = gtk_label_new(message);
    gtk_label_set_justify(GTK_LABEL(App->description_label),GTK_JUSTIFY_CENTER);
    gtk_label_set_xalign(GTK_LABEL(App->description_label), 0.5);
    gtk_box_pack_start(GTK_BOX(App->description_hbox),App->description_label,TRUE,TRUE,0);
    gtk_widget_set_name(App->description_label,"signup__description_label");

    // //?password label
    App->password_label = gtk_label_new("Password :");
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
    compApp->signup = App;
    g_signal_connect(G_OBJECT(App->submit),"clicked",G_CALLBACK(handleUserPasswordVerification),(gpointer)compApp);
    g_signal_connect(G_OBJECT(App->password_entry), "activate", G_CALLBACK(handleUserPasswordVerification), (gpointer)compApp);
        gtk_widget_set_halign(App->submit, GTK_ALIGN_CENTER);
    gtk_widget_set_name(App->submit, "signup__submit");

    //? cancel button
    App->cancel = gtk_button_new_with_label("Cancel");
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

void handleUserPasswordVerification(GtkWidget *butt, gpointer data){
    composedWindow *compApp;
    compApp = (composedWindow*)data;
    char password[100];
    char hashedPassword[100];
    strcpy(password, gtk_entry_get_text(compApp->signup->password_entry));
    strcpy(hashedPassword,hashPassword(password));
    if(verify_password(compApp->name,hashedPassword)==1){
        gtk_window_close(compApp->signup->window);
        gtk_widget_hide(compApp->App->welcome_window);
        create_dashboard((gpointer) compApp);
    }else{
        signup_password_error_dialog((gpointer)compApp);
    }
}

void signup_password_error_dialog(gpointer data){
    GtkWidget *dialog;
    GtkWidget *dialogContainer;
    GtkWidget *label;
    GtkWidget *button;
    dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog),"Mot de passe incorrect");
    gtk_widget_set_size_request(dialog,400,50);
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Le mot de passe que vous avez insérer est incorrect");
    button = gtk_button_new_with_label("Ok");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(close_dialog),(gpointer)dialog);
    gtk_container_add(GTK_CONTAINER(dialogContainer),label);
    gtk_container_add(GTK_CONTAINER(dialogContainer),button);
    gtk_widget_show_all(dialog);
}

void close_dialog(gpointer data){
    GtkWidget *dialog = (GtkWidget*)data;
    gtk_window_close(dialog);
}