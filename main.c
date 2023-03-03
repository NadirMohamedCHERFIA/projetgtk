#include <gtk/gtk.h>
#include "welcome.h"
#include "newUser.h"
#include "widgets.h"
#include "style.h"
int main(int argc, char *argv[]){
    MainWindow *App;
    App = g_malloc(sizeof(MainWindow));
    gtk_init(&argc, &argv);
    load_css();
    welcome_window((gpointer)App);
    gtk_main();
    return 0;
}