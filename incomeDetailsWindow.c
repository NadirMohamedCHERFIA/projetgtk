#include "incomeDetailsWindow.h"
static char MONTHS[12][10] = {"Janvier","Février","Mars","Mai","Juin","Juillet","Août","Septembre","Octobre","Novembre","Décembre"};


void handle_info_income(gpointer data){
    composedWindow *compApp = (composedWindow*)data;
    incomeDetailsWindow *App;
    App = compApp->income_details_window;
    for (int i = 0; i < App->nbr_rows; i++)
    {
        // g_print("%s",App->income_details[i].category);
        char info[1000];
        GtkWidget *valuebox;
        GtkWidget *value;
        GtkWidget *categoryBox;
        GtkWidget *category;
        GtkWidget *dateBox;
        GtkWidget *date;
        GtkWidget *descriptionBox;
        GtkWidget *description;
        sprintf(info, "%f \t %s \t %s \t %s", App->income_details[i].value, App->income_details[i].category, App->income_details[i].date, App->income_details[i].description);
        App->info_row_box[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(App->detailsBox), App->info_row_box[i], TRUE, TRUE, 0);
        gtk_widget_set_size_request(App->info_row_box[i],100,60);
        gtk_widget_set_name(App->info_row_box[i], "info__row");
        //*****************************************************
        // valuebox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
        // gtk_box_pack_start(GTK_BOX(App->info_row_box[i]),valuebox,TRUE,FALSE,0);
        // gtk_widget_set_size_request(valuebox,25,70);
        // //*****************************************************
        // categoryBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        // gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), categoryBox, TRUE, FALSE, 0);
        // gtk_widget_set_size_request(categoryBox, 25, 70);
        // //*****************************************************
        // descriptionBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        // gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), descriptionBox, TRUE, FALSE, 0);
        // gtk_widget_set_size_request(descriptionBox, 25, 70);

        // //************************************************
        // value = gtk_label_new(itoa(App->income_details[i].value));
        // gtk_box_pack_start(GTK_BOX(valuebox),value,TRUE,TRUE,0);

        // //************************************************
        // category = gtk_label_new(App->income_details[i].category);
        // gtk_box_pack_start(GTK_BOX(categoryBox), category, TRUE, TRUE, 0);

        // //************************************************
        // date = gtk_label_new(App->income_details[i].date);
        // gtk_box_pack_start(GTK_BOX(dateBox), date, TRUE, TRUE, 0);

        char stringvalue[5];
        sprintf(stringvalue, "%f  €", App->income_details[i].value);
        value = gtk_label_new(stringvalue);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]),value,TRUE,TRUE,0);
        gtk_label_set_justify(GTK_LABEL(value),GTK_JUSTIFY_CENTER);
        gtk_label_set_xalign(GTK_LABEL(value),0.5);
        category = gtk_label_new(App->income_details[i].category);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), category, TRUE, FALSE, 0);
        gtk_label_set_justify(GTK_LABEL(category), GTK_JUSTIFY_CENTER);
        gtk_label_set_xalign(GTK_LABEL(category), 0.5);

        date = gtk_label_new(App->income_details[i].date);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), date, TRUE, TRUE, 0);
        description = gtk_label_new(App->income_details[i].description);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), description, TRUE, TRUE, 0);

        // App->info_row_label[i] = gtk_label_new();
        // gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), App->info_row_label[i], TRUE, TRUE, 0);
    }
}

void create_income_details_window(GtkWidget *butt, gpointer data){
    gint HEIGHT = getScreenHeight();
    gint WIDTH = getScreenWidth();
    gint BORDERWIDTH = 60;
    composedWindow *compApp = (composedWindow*)data;
    incomeDetailsWindow *App;
    App = compApp->income_details_window;

    //? window
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(App->window),GTK_WIN_POS_CENTER);
    gtk_widget_set_name(App->window,"income_details_window");
    gtk_container_set_border_width(GTK_CONTAINER(App->window),BORDERWIDTH);
    gtk_window_set_default_size(GTK_WINDOW(App->window),WIDTH*0.7,HEIGHT*0.8);
    gtk_window_set_title(GTK_WINDOW(App->window),"Les détails du revenues");

    //?header bar
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar), "Les détails du revenues");
    gtk_window_set_titlebar(GTK_WINDOW(App->window), titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar, "titleBar");


    //? box 
    App->box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(App->window),App->box);


    //? scrolled window
    App->scrolledWindow = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(App->scrolledWindow),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    // gtk_container_add(GTK_CONTAINER(App->detailsBox),App->scrolledWindow);
    gtk_box_pack_start(GTK_BOX(App->box),App->scrolledWindow,TRUE,TRUE,0);
    // gtk_widget_set_size_request(App->scrolledWindow,WIDTH*0.6,HEIGHT*0.1);

    //? info box
    App->detailsBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    // gtk_box_pack_start(GTK_BOX(App->box),App->detailsBox,FALSE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(App->scrolledWindow),App->detailsBox);
    gtk_widget_set_name(App->detailsBox,"shadowed__box");


    //? info boxes

    get_user_income_details((gpointer)compApp);

    gtk_widget_show_all(App->window);
}