#include <gtk/gtk.h>
#include "welcome.h"
#include "newUser.h"
#include "widgets.h"
#include "style.h"
#include "imageWindow.h"
#include "depenseAddWindow.h"
int main(int argc, char *argv[]){
    composedWindow *App;
    App = g_malloc(sizeof(composedWindow));
    newUserWindow *newUser = g_malloc(sizeof(newUserWindow));
    App->newUser = newUser;
    MainWindow *welcome = g_malloc(sizeof(MainWindow));
    App->first_load = 1;
    App->App = welcome;
    gtk_init(&argc, &argv);
    load_css();
    image_window((gpointer)App);
    gtk_main();
    return 0;
}