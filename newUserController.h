#ifndef __NEWUSERCONTROLLER_H__
#define __NEWUSERCONTROLLER_H__
#include <gtk/gtk.h>
#include "string.h"
#include "directoryManagement.h"
#include "widgets.h"
#include "dbconnect.h"
#include "usersList.h"
void handleBack(GtkWidget *butt, gpointer data)
{
    MainWindow *App;
    App=(MainWindow*)data;
    gtk_window_close(GTK_WINDOW(App->new_user_window));
    
    gtk_widget_show(App->welcome_window);
    gtk_label_set_markup(GTK_LABEL(App->user_label[3]),"changed");
    get_users((gpointer)App);
    handle_adding_new_user((gpointer)App);
}

void handleNewUserSubmit(GtkWidget *but,gpointer data){
    MainWindow *myApp;
    myApp = (MainWindow *)data;
    char *user, *password, *password_confirm;
    user = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_username_input));
    password = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input));
    password_confirm = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input_confirm));
    add_new_user(user,password);
    g_print("username:%s\npassword:%s", user, password);
}

#endif