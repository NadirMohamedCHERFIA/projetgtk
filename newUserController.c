#include "newUserController.h"
#include "passwordHashing.h"
void handleBack(GtkWidget *butt, gpointer data)
{
    composedWindow *compApp;
    compApp = (composedWindow*)data;
    MainWindow *App;
    App = compApp->App;
    get_users((gpointer)compApp);    
    gtk_widget_show_all(compApp->App->welcome_window);
    gtk_window_close(GTK_WINDOW(compApp->newUser->new_user_window));
}

void handleNewUserSubmit(GtkWidget *but, gpointer data)
{
    composedWindow *compApp;
    compApp = (composedWindow *)data;
    newUserWindow *myApp;
    myApp = compApp->newUser;
    char *user, password[100], *password_confirm,*hashedPassword;
    user = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_username_input));
    // password = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input));
    strcpy(password, gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input)));
        password_confirm = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input_confirm));
    g_print("username:%s\npassword:%s", user, password);
    if(user_exist(user)==0){
        if(strcmp(password,password_confirm)!=0 || strlen(password)==0 ){
            password_verification_dialog();
        }else{
            hashedPassword = hashPassword(password);
            add_new_user(user, hashedPassword);
            get_users(compApp);
            handle_users(compApp->App);
            // gtk_widget_show_all(compApp->App->welcome_window);
            gtk_window_close(GTK_WINDOW(myApp->new_user_window));
            // gtk_widget_hide(compApp->App->welcome_vbox_users);
            strcpy(compApp->name,user);
            create_dashboard((gpointer)compApp);
            // get_user_id(compApp->name);
            create_created_dialog(user);

            // gtk_widget_show(compApp->App->welcome_window);
        }
    }else{
        user_exist_dialog();
    }
}

void create_created_dialog(char *name){

    GtkWidget *dialog;
    GtkWidget *dialogContainer;
    GtkWidget *vbox;
    GtkWidget *label;
    dialog = gtk_dialog_new();
    char message[100];
    strcpy(message,"Utilisateur ");
    strcat(message,name);
    strcat(message, " crée avec succes");
    gtk_window_set_title(GTK_WINDOW(dialog),"Utilisateur crée avec succes");
    gtk_widget_set_size_request(dialog,400,50);

    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(dialogContainer),vbox);

    label = gtk_label_new(message);
    gtk_box_pack_start(GTK_BOX(vbox),label,TRUE,TRUE,0);

    gtk_widget_show_all(dialog);

    int timeout_id = g_timeout_add_seconds(3, destroy_creation_dialog_info,dialog);
}

int destroy_creation_dialog_info(gpointer data){
    GtkWidget *dialog;
    dialog=(GtkWidget*)data;
    gtk_widget_destroy(dialog);
    // gtk_window_close(GTK_WINDOW(dialog));
    return G_SOURCE_REMOVE;
}

void password_verification_dialog(){
    GtkWidget *dialog;
    GtkDialog *dialogContainer;
    GtkWidget *dialogLabel;
    gint response;
    dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog),"mot de passe error");
    gtk_widget_set_size_request(dialog,400,50);
    dialogContainer = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    dialogLabel = gtk_label_new("Veuillez entrer le même mot de passe!(mot de passe obligatoire)");
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
    gint response;
    dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "username error");
    gtk_widget_set_size_request(dialog,400,50);
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