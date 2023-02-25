#include <gtk/gtk.h>
#include "string.h"
#ifndef __NEWUSERCONTROLLER_H__
#define __NEWUSERCONTROLLER_H__
void handleBack(GtkWidget *butt, gpointer data)
{
    MainWindow *myApp;
    myApp = (MainWindow *)data;


}

void handleNewUserSubmit(GtkWidget *but,gpointer data){
    MainWindow *App;
    App=(MainWindow*)data;
    char * test;
    test = gtk_entry_get_text(GTK_ENTRY(App->new_user_username_input));
    gtk_label_set_markup(GTK_LABEL(App->new_user_username_label),test);
    // if(strcmp(test,"nadir")==0){
    //     g_print("ok");
    // }
}

#endif