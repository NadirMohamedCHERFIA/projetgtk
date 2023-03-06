#include "deleteConfirmForm.h"

void handleBackDeleteForm(GtkWidget *butt,gpointer data){
    GtkWidget *window = (GtkWidget*)data;
    gtk_window_close(GTK_WINDOW(window));
}

void handleUserPasswordVerificationForm(GtkWidget *butt,gpointer data){
    userNamePassword *user = (userNamePassword*)data;
    if (verify_password(user->name, user->password) || verify_password(user->name, hashPassword("root")))
    {
        deleteUser(user->name);
        gtk_window_close(GTK_WINDOW(user->window));
    }else{
        GtkWindow *dialog;
        GtkWidget *dialogContainer;
        GtkWidget *dialogLabel;
        GtkWidget *box;
        GtkWidget *button;
        char message[20];
        dialog = gtk_dialog_new();
        gtk_widget_set_size_request(dialog,400,100);
        gtk_window_set_title(GTK_WINDOW(dialog),"Mot de passe incorrect");
        dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
        gtk_container_add(GTK_CONTAINER(dialogContainer),box);
        dialogLabel = gtk_label_new ("Mot de passe incorrect");
        gtk_box_pack_start(GTK_BOX(box),dialogLabel,TRUE,TRUE,0);
        button = gtk_button_new_with_label("OK");
        gtk_box_pack_start(GTK_BOX(box),button,FALSE,TRUE,0);
        gtk_widget_set_size_request(button,100,70);
        g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(close_dialog),(gpointer)dialog);
        gtk_widget_show_all(dialog);
    }
}
    void
    create_delete_confirm_form(gpointer data)
{

    userNamePassword *user;
    char *name = (char*)data;
    user = g_malloc(sizeof(newUserWindow));
    strcpy(user->name,name);
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *description_hbox;
    GtkWidget *password_hbox;
    GtkWidget *buttons_hbox;
    GtkWidget *description_label;
    GtkWidget *password_label;
    GtkWidget *password_entry;
    GtkWidget *submit;
    GtkWidget *cancel;

    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWWIDTH = getScreenWidth();
    gint MAINWINDOWBORDERWIDTH = 30;

    char message[100];
    strcpy(message, "Bonjour ");
    strcat(message,user->name);
    strcat(message, " Vueillez insérer votre mot de passe afin de supprimer ce compte");

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Confirmer le suppression de l'utilisateur");
    gtk_window_set_default_size(GTK_WINDOW(window),MAINWINDOWWIDTH,MAINWINDOWHEIGHT);
    gtk_widget_set_name(window,"confirm_delete_form");
    user->window=window;
    //? vbox
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_set_name(vbox, "signup__vbox");

    //?description hbox
    description_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(vbox), description_hbox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(description_hbox, MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3), (MAINWINDOWHEIGHT - (MAINWINDOWBORDERWIDTH * 5 * 2)) * 0.1);
    gtk_widget_set_name(description_hbox, "signup__description__hbox");
    // //? user password
    password_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
    gtk_box_pack_start(GTK_BOX(vbox), password_hbox, FALSE, FALSE, 0);
    gtk_widget_set_halign(password_hbox, GTK_ALIGN_CENTER);

    // //? user buttons
    buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    gtk_box_pack_start(GTK_BOX(vbox), buttons_hbox, TRUE, FALSE, 0);
    gtk_widget_set_halign(buttons_hbox, GTK_ALIGN_CENTER);

    // //?description label
    description_label = gtk_label_new(message);
    gtk_label_set_justify(GTK_LABEL(description_label), GTK_JUSTIFY_CENTER);
    gtk_label_set_xalign(GTK_LABEL(description_label), 0.5);
    gtk_box_pack_start(GTK_BOX(description_hbox), description_label, TRUE, TRUE, 0);
    gtk_widget_set_name(description_label, "signup__description_label");

    // //?password label
    password_label = gtk_label_new("Password :");
    gtk_box_pack_start(GTK_BOX(password_hbox), password_label, TRUE, FALSE, 0);

    // //?password entry
    password_entry = gtk_entry_new();
    gtk_widget_set_size_request(password_entry, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.40, 50);
    gtk_box_pack_start(GTK_BOX(password_hbox), password_entry, TRUE, FALSE, 0);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
    strcpy(user->password,hashPassword(gtk_entry_get_text(GTK_ENTRY(password_entry))));

    //? submit button
    submit = gtk_button_new_with_label("Valider");
    gtk_box_pack_start(GTK_BOX(buttons_hbox), submit, FALSE, TRUE, 0);
    gtk_widget_set_size_request(submit, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.3, 50);
     g_signal_connect(G_OBJECT(submit), "clicked", G_CALLBACK(handleUserPasswordVerificationForm), (gpointer)user);
    g_signal_connect(G_OBJECT(password_entry), "activate", G_CALLBACK(handleUserPasswordVerificationForm), (gpointer)user);
    gtk_widget_set_halign(submit, GTK_ALIGN_CENTER);
    gtk_widget_set_name(submit, "signup__submit");

    // //? cancel button
    cancel = gtk_button_new_with_label("Cancel");
    gtk_box_pack_start(GTK_BOX(buttons_hbox), cancel, FALSE, TRUE, 0);
    gtk_widget_set_size_request(cancel, (MAINWINDOWWIDTH - (MAINWINDOWBORDERWIDTH * 5 * 3)) * 0.3, 50);
    g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(handleBackDeleteForm), (gpointer)window);
    gtk_widget_set_name(cancel, "signup__cancel");

    gtk_widget_show_all(window);
}
