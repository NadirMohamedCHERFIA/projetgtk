#include "widgets.h"
#include "style.h"
#include "newUser.h"

int welcome_window(int argc ,char *argv[]){
    MainWindow *App;
    const gchar *const WELCOMEWINDOWTITLE ="GESTION DE DEPENSES";
    App = g_malloc(sizeof(MainWindow));
    gtk_init(&argc,&argv);
    load_css();
    gint empty=0;

    //?Welcome window
    App->welcome_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->welcome_window),WELCOMEWINDOWTITLE);
    gtk_window_set_default_size(GTK_WINDOW(App->welcome_window),1200,800);
    // gtk_window_fullscreen(App->welcome_window);
    g_signal_connect(GTK_WINDOW(App->welcome_window),"destroy",gtk_main_quit,NULL);
    gtk_window_set_position(GTK_WINDOW(App->welcome_window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(App->welcome_window),30);
    gtk_widget_set_name(App->welcome_window,"main__window");

    //? welcome wrapper vbox
    App->welcome_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,30);
    gtk_container_add(GTK_CONTAINER(App->welcome_window),App->welcome_vbox);

    //?users vertical box
    App->welcome_vbox_users = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    // gtk_widget_set_size_request(App->welcome_vbox_users,600,300);
    gtk_widget_set_name(App->welcome_vbox_users,"users__vbox");
    if(!empty){
        gtk_box_pack_start(GTK_BOX(App->welcome_vbox),App->welcome_vbox_users,TRUE,TRUE,0);
    }

    //?buttons vertical box
    App->welcome_vbox_buttons = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox),App->welcome_vbox_buttons,FALSE,FALSE,0);
    gtk_widget_set_name(App->welcome_vbox_buttons,"buttons__vbox");

    //?Adding user button
    App->welcome_new_user_button = gtk_button_new_with_label("Ajouet un nouveau utilisateur");
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox_buttons),App->welcome_new_user_button,FALSE,TRUE,40);
    gtk_widget_set_name(App->welcome_new_user_button,"add__user__button");
    g_signal_connect(G_OBJECT(App->welcome_new_user_button),"clicked",G_CALLBACK(create_new_user),NULL);
    gtk_widget_set_size_request(App->welcome_new_user_button,200,50);

    //?welcome quit
    App->welcome_quit = gtk_button_new_with_label("Exit");
    gtk_box_pack_start(GTK_BOX(App->welcome_vbox_buttons), App->welcome_quit, TRUE, FALSE, 40);
    g_signal_connect(GTK_BUTTON(App->welcome_quit), "clicked", gtk_main_quit, NULL);
    gtk_widget_set_name(App->welcome_quit, "quit__button");
    gtk_widget_set_size_request(App->welcome_quit, 200, 50);

    gtk_widget_show_all(App->welcome_window);
    // gtk_main();
    // g_free(App);
    // return 0;
}