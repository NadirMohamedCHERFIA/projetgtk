#include "incomeDetailsWindow.h"
static char MONTHS[12][10] = {"Janvier", "Février", "Mars", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};

void handle_info_depenses(gpointer data)
{
    composedWindow *compApp = (composedWindow *)data;
    depenseDetailsWindow *App;
    App = compApp->depenses_details_window;

    gint HEIGHT = getScreenHeight();
    gint WIDTH = getScreenWidth();

    for (int i = 0; i < App->nbr_rows; i++)
    {
        g_print("%s",App->depenses_details[i].category);
        char info[1000];
        GtkWidget *valuebox;
        GtkWidget *value;
        GtkWidget *categoryBox;
        GtkWidget *category;
        GtkWidget *dateBox;
        GtkWidget *date;
        GtkWidget *descriptionBox;
        GtkWidget *description;
        // sprintf(info, "%f \t %s \t %s \t %s", App->depenses_details[i].value, App->income_details[i].category, App->income_details[i].date, App->income_details[i].description);

        App->info_row_box[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
        gtk_box_pack_start(GTK_BOX(App->detailsBox), App->info_row_box[i], TRUE, TRUE, 0);
        gtk_widget_set_name(App->info_row_box[i], "squared__box");
        gtk_widget_set_size_request(App->info_row_box[i],100,60);
        // gtk_widget_set_name(valuebox,"squared__box");

        //*****************************************************
        valuebox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), valuebox, TRUE, TRUE, 0);
        gtk_widget_set_size_request(valuebox, WIDTH * 0.1, 70);
        // gtk_widget_set_name(valuebox,"squared__box");

        // // //*****************************************************
        categoryBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), categoryBox, TRUE, TRUE, 0);
        gtk_widget_set_size_request(categoryBox, WIDTH * 0.1, 70);
        // // gtk_widget_set_name(categoryBox, "squared__box");

        //*****************************************************
        dateBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), dateBox, TRUE, TRUE, 0);
        gtk_widget_set_size_request(dateBox, WIDTH * 0.1, 70);
        // // gtk_widget_set_name(dateBox, "squared__box");

        //*****************************************************
        descriptionBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_pack_start(GTK_BOX(App->info_row_box[i]), descriptionBox, TRUE, TRUE, 0);
        gtk_widget_set_size_request(descriptionBox, WIDTH * 0.1, 70);
        // gtk_widget_set_name(descriptionBox, "squared__box");

        char stringvalue[5];
        sprintf(stringvalue, "%.2f  €", App->depenses_details[i].value);
        value = gtk_label_new(stringvalue);
        gtk_box_pack_start(GTK_BOX(valuebox), value, TRUE, TRUE, 0);
        gtk_label_set_justify(GTK_LABEL(value), GTK_JUSTIFY_CENTER);
        gtk_label_set_xalign(GTK_LABEL(value), 0.5);
        //**************************************************************
        category = gtk_label_new(App->depenses_details[i].category);
        gtk_box_pack_start(GTK_BOX(categoryBox), category, TRUE, TRUE, 0);
        gtk_label_set_justify(GTK_LABEL(category), GTK_JUSTIFY_CENTER);
        gtk_label_set_xalign(GTK_LABEL(category), 0.5);
        //*************************************************************
        date = gtk_label_new(App->depenses_details[i].date);
        gtk_box_pack_start(GTK_BOX(dateBox), date, TRUE, TRUE, 0);
        //*******************************************************************
        description = gtk_label_new(App->depenses_details[i].description);
        gtk_box_pack_start(GTK_BOX(descriptionBox), description, TRUE, TRUE, 0);
    }
}

void create_depenses_details_window(GtkWidget *butt, gpointer data)
{
    gint HEIGHT = getScreenHeight();
    gint WIDTH = getScreenWidth();
    gint BORDERWIDTH = 60;
    composedWindow *compApp = (composedWindow *)data;
    depenseDetailsWindow *App;
    App = compApp->depenses_details_window;

    //? window
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(App->window), GTK_WIN_POS_CENTER);
    gtk_widget_set_name(App->window, "income_details_window");
    gtk_container_set_border_width(GTK_CONTAINER(App->window), BORDERWIDTH);
    gtk_window_set_default_size(GTK_WINDOW(App->window), WIDTH * 0.7, HEIGHT * 0.8);
    gtk_window_set_title(GTK_WINDOW(App->window), "Les détails du depenses");

    //?header bar
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar), "Les détails du depenses");
    gtk_window_set_titlebar(GTK_WINDOW(App->window), titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar, "titleBar");

    //? box
    App->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
    gtk_container_add(GTK_CONTAINER(App->window), App->box);

    //? description box
    App->descriptionBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->box), App->descriptionBox, FALSE, TRUE, 0);
    gtk_widget_set_name(App->descriptionBox, "shadowed__window");
    // gtk_container_set_border_width(GTK_CONTAINER(App->descriptionBox), 100);

    //? description label
    App->descriptionLabel = gtk_label_new("Vos depenses de ce mois");
    gtk_box_pack_start(GTK_BOX(App->descriptionBox), App->descriptionLabel, FALSE, TRUE, 0);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //? header desc box
    App->headerDesc = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(App->box), App->headerDesc, FALSE, TRUE, 0);
    gtk_widget_set_name(App->headerDesc, "shadowed__box");

    //?
    App->header_valueBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->headerDesc), App->header_valueBox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->header_valueBox, WIDTH * 0.1, 70);
    // gtk_widget_set_name(App->header_valueBox, "squared__box");
    App->header_valueBox_label = gtk_label_new("Valeur");
    gtk_box_pack_start(GTK_BOX(App->header_valueBox), App->header_valueBox_label, TRUE, TRUE, 0);
    //?
    App->header_categoryBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->headerDesc), App->header_categoryBox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->header_categoryBox, WIDTH * 0.1, 70);
    // gtk_widget_set_name(App->header_categoryBox, "squared__box");
    App->header_categoryBox_label = gtk_label_new("Categorie");
    gtk_box_pack_start(GTK_BOX(App->header_categoryBox), App->header_categoryBox_label, TRUE, TRUE, 0);

    //?
    App->header_dateBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->headerDesc), App->header_dateBox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->header_dateBox, WIDTH * 0.1, 70);
    // gtk_widget_set_name(App->header_dateBox, "squared__box");
    App->header_dateBox_label = gtk_label_new("Date");
    gtk_box_pack_start(GTK_BOX(App->header_dateBox), App->header_dateBox_label, TRUE, TRUE, 0);

    //?
    App->header_descriptionBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(App->headerDesc), App->header_descriptionBox, TRUE, FALSE, 0);
    gtk_widget_set_size_request(App->header_descriptionBox, WIDTH * 0.1, 70);
    // gtk_widget_set_name(App->header_descriptionBox, "squared__box");
    App->header_descriptionBox_label = gtk_label_new("Description");
    gtk_box_pack_start(GTK_BOX(App->header_descriptionBox), App->header_descriptionBox_label, TRUE, TRUE, 0);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //? scrolled window
    App->scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(App->scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    // gtk_container_add(GTK_CONTAINER(App->detailsBox),App->scrolledWindow);
    gtk_box_pack_start(GTK_BOX(App->box), App->scrolledWindow, TRUE, TRUE, 0);
    // gtk_widget_set_size_request(App->scrolledWindow,WIDTH*0.6,HEIGHT*0.1);

    //? info box
    App->detailsBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // gtk_box_pack_start(GTK_BOX(App->box),App->detailsBox,FALSE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(App->scrolledWindow), App->detailsBox);
    gtk_widget_set_name(App->detailsBox, "shadowed__box");

    //? info boxes

    get_user_depenses_details((gpointer)compApp);

    gtk_widget_show_all(App->window);
}