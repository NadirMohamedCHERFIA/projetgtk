#include "imageWindow.h"

static void handleWindow(GtkWidget *butt, gpointer data){
    composedWindow *compApp =(composedWindow*)data;
    gtk_window_close(GTK_WINDOW(compApp->imagewind->window));
    welcome_window((gpointer) compApp);
}
void image_window(gpointer data){
    composedWindow *compApp=(composedWindow*)data;
    imageWindow *App = g_malloc(sizeof(imageWindow));
    gint WIDTH = getScreenWidth();
    gint HEIGHT = getScreenHeight();
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(App->window),WIDTH,HEIGHT);
    gtk_widget_set_name(App->window,"image__window");
    gtk_window_set_title(GTK_WINDOW(App->window),"GESTIOND DE DEPENSES");
    gtk_container_set_border_width(GTK_CONTAINER(App->window),200);
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar), "GESTION DE DEPENSES");
    gtk_window_set_titlebar(GTK_WINDOW(App->window), titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar, "titleBar");

    App->box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(App->window),App->box);


    App->image = gtk_image_new_from_file("background.png");
    gtk_box_pack_start(GTK_BOX(App->box),App->image,FALSE,TRUE,0);
    gtk_widget_set_name(App->image,"image");

    App->button=gtk_button_new_with_label("Gérer son budget!");
    gtk_box_pack_start(GTK_BOX(App->box),App->button,FALSE,FALSE,0);
    gtk_widget_set_size_request(App->button,100,70);
    gtk_widget_set_name(App->button,"commencer__button");
    g_signal_connect(G_OBJECT(App->button),"clicked",G_CALLBACK(handleWindow),(gpointer) compApp);

    compApp->imagewind = App;

    gtk_widget_show_all(App->window);
}