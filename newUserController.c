#include "newUserController.h"
#include "passwordHashing.h"
void handleBack(GtkWidget *butt, gpointer data)
{
    MainWindow *App;
    App = (MainWindow *)data;
    gtk_window_close(GTK_WINDOW(App->new_user_window));
    gtk_widget_show(App->welcome_window);
    gtk_label_set_markup(GTK_LABEL(App->user_label[3]), "changed");
    get_users((gpointer)App);
    handle_adding_new_user((gpointer)App);
}

void handleNewUserSubmit(GtkWidget *but, gpointer data)
{
    MainWindow *myApp;
    myApp = (MainWindow *)data;
    char *user, *password, *password_confirm,*hashedPassword;
    user = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_username_input));
    password = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input));
    password_confirm = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input_confirm));
    g_print("username:%s\npassword:%s", user, password);
    // if(user_exist(user)){
        if(strcmp(password,password_confirm)!=0){
            password_verification_dialog();
        }else{
            hashedPassword = hashPassword(password);
            add_new_user(user, hashedPassword);
            gtk_window_close(GTK_WINDOW(myApp->new_user_window));
            get_users(myApp);
            handle_users(myApp);
            gtk_widget_show(myApp->welcome_window);
        }
    // }else{
    //     user_exist_dialog();
    // }
}

void password_verification_dialog(){
    GtkWidget *dialog;
    GtkDialog *dialogContainer;
    GtkWidget *dialogLabel;
    dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog),"mot de passe error");
    gtk_widget_set_size_request(dialog,400,50);
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    dialogLabel = gtk_label_new("Veuillez entrer le même mot de passe!");
    gtk_container_add(GTK_CONTAINER(dialogContainer),dialogLabel);
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);
    gtk_widget_show_all(dialog);
    if(gtk_dialog_run(GTK_DIALOG(dialog))==1){
        gtk_widget_destroy(dialog);
    }
}

void user_exist_dialog()
{
    GtkWidget *dialog;
    GtkDialog *dialogContainer;
    GtkWidget *dialogLabel;
    dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "user exist error");
    gtk_widget_set_size_request(dialog, 400, 50);
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    dialogLabel = gtk_label_new("Veuillez entrer un autre nom d'utilisateur celui là déjà exist!");
    gtk_container_add(GTK_CONTAINER(dialogContainer), dialogLabel);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Ok", 1);
    gtk_widget_show_all(dialog);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == 1)
    {
        gtk_widget_destroy(dialog);
    }
}