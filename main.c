#include <gtk/gtk.h>
#include "welcome.h"
#include "newUser.h"
#include "widgets.h"
#include "style.h"
int main(int argc, char *argv[]){
    welcome_window(argc,argv);
    gtk_main();
    return 0;
}