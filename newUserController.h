#ifndef __NEWUSERCONTROLLER_H__
#define __NEWUSERCONTROLLER_H__
#include <gtk/gtk.h>
#include "string.h"
#include "directoryManagement.h"
#include "widgets.h"
void handleBack(GtkWidget *butt, gpointer data)
{
    MainWindow *App;
    App=(MainWindow*)data;
    gtk_window_close(GTK_WINDOW(App->new_user_window));
}

void handleNewUserSubmit(GtkWidget *but,gpointer data){
    MainWindow *myApp;
    myApp = (MainWindow *)data;
    char *user, *password;
    user = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_username_input));
    password = gtk_entry_get_text(GTK_ENTRY(myApp->new_user_password_input));

    g_print("username:%s\npassword:%s", user, password);
}

#endif