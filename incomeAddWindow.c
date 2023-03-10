#include "incomeAddWindow.h"

void handleAddIncomeConfirm(GtkWidget *butt,gpointer data){
    composedWindow *compApp = (composedWindow*)data;
    GtkTextBuffer *buffer;
    GtkTextIter start, end;
    char value[10];
    strcpy(value, gtk_entry_get_text(GTK_ENTRY(compApp->incomeaddwindow->valueEntry))) ;
    char *description;
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(compApp->incomeaddwindow->valueDescriptionEntry));
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    description = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    // description = gtk_entry_get_text(compApp->incomeaddwindow->valueDescriptionEntry);
    // strcpy(description,gtk_text_view_get_text(GTK_TEXT_VIEW(compApp->incomeaddwindow->valueDescriptionEntry)));
    g_print("value : %s ",value);
    g_print("\n desc : %s",description);
    g_print(" float value : %f",atof(value));
    // g_print("user id : %d",compApp->id);
    add_income(atof(value),compApp->incomeaddwindow->selected_type,compApp->id,compApp->calendar_window->date_formated,description);
    get_total_depenses_and_income((gpointer)compApp);
    char depenses[100];
    sprintf(depenses, "Les depenses totales de ce mois \n\n %.2lf €", compApp->total_depenses);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_total_depenses_label), depenses);
    char income[100];
    sprintf(income, "Le revenue total de ce mois \n\n %.2lf €", compApp->total_income);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_total_income_label), income);
    char economy[100];
    sprintf(economy, "L'economie de ce mois \n\n %.2lf €", compApp->total_income - compApp->total_depenses);
    gtk_label_set_markup(GTK_LABEL(compApp->dashboard->dashboard_economy_label), economy);

    //!!!!!!!!!!!!!!!!ADD a dialog to confirm the adding value

    gtk_window_close(GTK_WINDOW(compApp->incomeaddwindow->window));

}

    static void
    handleMonthlyType(GtkToggleButton *button, gpointer data)
{
    incomeAddWindow *App = (incomeAddWindow*)data;
    if (gtk_toggle_button_get_active(button))
    {
        App->selected_type=1;

    }else{
        App->selected_type = 2;
    }

    g_print("selected_type : %d",App->selected_type);
}

    void
    create_income_add_window(GtkWidget *butt, gpointer data)
{
    composedWindow *compApp = (composedWindow*)data;
    incomeAddWindow *App = g_malloc(sizeof(incomeAddWindow));

    gint MAINWINDOWWIDTH = getScreenWidth();
    gint MAINWINDOWHEIGHT = getScreenHeight();
    gint MAINWINDOWBORDERWIDTH =60;
    //? windowpp
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(App->window),"Ajouter un revenue");
    gtk_window_set_position(GTK_WINDOW(App->window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(App->window),MAINWINDOWWIDTH*0.4,MAINWINDOWHEIGHT*0.4);
    gtk_container_set_border_width(GTK_CONTAINER(App->window),MAINWINDOWBORDERWIDTH);
    gtk_widget_set_name(App->window,"income__add__window");
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar), "Ajouter un revenue");
    gtk_window_set_titlebar(GTK_WINDOW(App->window), titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar, "titleBar");
    App->selected_type=1;
    //? vbox
    App->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,30);
    gtk_container_add(GTK_CONTAINER(App->window),App->vbox);
    gtk_widget_set_name(App->vbox,"income__add__vbox");

    //? description box
    App->descriptionbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->descriptionbox,TRUE,TRUE,0);
    gtk_widget_set_name(App->descriptionbox,"income__add__description__box");
    gtk_widget_set_size_request(App->descriptionbox,MAINWINDOWWIDTH*0.4,50);
    
    //? description label
    App->descriptionlabel = gtk_label_new("Ajouter un nouveau revenue");
    gtk_box_pack_start(GTK_BOX(App->descriptionbox),App->descriptionlabel,TRUE,FALSE,0);
    gtk_label_set_justify(GTK_LABEL(App->descriptionlabel),GTK_JUSTIFY_CENTER);

    //? income type box
    App->income_type_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 40);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->income_type_box,TRUE,FALSE,0);
    gtk_widget_set_halign(App->income_type_box,GTK_ALIGN_CENTER);

    //? type label
    App->typeLabel = gtk_label_new("Le type du revenue:");
    gtk_box_pack_start(GTK_BOX(App->income_type_box),App->typeLabel,TRUE,TRUE,0);

    //? monthly income radio
    App->income_monthly_radio = gtk_radio_button_new_with_label(NULL,"Mansuelle");
    gtk_box_pack_start(GTK_BOX(App->income_type_box),App->income_monthly_radio,TRUE,TRUE,0);
    g_signal_connect(G_OBJECT(App->income_monthly_radio),"toggled",G_CALLBACK(handleMonthlyType),(gpointer)App);

    //? not_ monthly income radio
    App->income_not_monthly_radio = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(App->income_monthly_radio),"Non Mansuelle");
    gtk_box_pack_start(GTK_BOX(App->income_type_box), App->income_not_monthly_radio, TRUE, TRUE, 0);

    //? date box
    App->databox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->databox,FALSE,FALSE,0);

    //? date label 
    App->dateLabel = gtk_label_new(NULL);
    char date[100];
    sprintf(date,"Date : %s",compApp->date_string);
    gtk_label_set_markup(GTK_LABEL(App->dateLabel),date);
    gtk_box_pack_start(GTK_BOX(App->databox),App->dateLabel,TRUE,FALSE,0);
    
    //? modify button 
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("logo.png", NULL);
    GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);
    App->modifyButton = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(App->modifyButton),image);
    gtk_box_pack_start(GTK_BOX(App->databox),App->modifyButton,FALSE,FALSE,0);
    g_signal_connect(G_OBJECT(App->modifyButton),"clicked",G_CALLBACK(handleCalendar),(gpointer)compApp);


    //? value box
    App->valuebox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->valuebox,TRUE,FALSE,0);
    gtk_widget_set_halign(App->valuebox,GTK_ALIGN_CENTER);

    //? value label
    App->valueLabel = gtk_label_new("Le montant du revenue(€) : ");
    gtk_box_pack_start(GTK_BOX(App->valuebox),App->valueLabel,FALSE,FALSE,0);
    gtk_entry_set_placeholder_text(GTK_ENTRY(App->valuebox), "Ex:2000");
    gtk_widget_set_size_request(App->valueLabel, MAINWINDOWWIDTH * 0.2, 50);

    //? value entry
    App->valueEntry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(App->valuebox),App->valueEntry,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->valueEntry,MAINWINDOWWIDTH*0.2,50);
    // gtk_entry_set_input_purpose(GTK_ENTRY(App->valueEntry), GTK_INPUT_PURPOSE_NUMBER);
    // gtk_entry_set_input_hints(GTK_ENTRY(App->valueEntry), GTK_INPUT_HINT_NUMERIC);
    //? value description box
    App->valueDescriptionBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->valueDescriptionBox,TRUE,FALSE,0);
    gtk_widget_set_halign(App->valueDescriptionBox,GTK_ALIGN_CENTER);

    //? value description label
    App->valueDescriptionLabel = gtk_label_new("Description (facultatif) : ");
    gtk_box_pack_start(GTK_BOX(App->valueDescriptionBox),App->valueDescriptionLabel,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->valueDescriptionLabel, MAINWINDOWWIDTH * 0.2, 50);

    //? value descrition text view
    App->valueDescriptionEntry = gtk_text_view_new();
    gtk_widget_set_name(App->valueDescriptionEntry,"textview");

    //? value descriptino text view scrolled window
    App->textViewScrolledWindow = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(App->textViewScrolledWindow),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(App->textViewScrolledWindow),App->valueDescriptionEntry);
    gtk_box_pack_start(GTK_BOX(App->valueDescriptionBox),App->textViewScrolledWindow,FALSE,TRUE,0);
    gtk_widget_set_size_request(App->textViewScrolledWindow, MAINWINDOWWIDTH * 0.2, 50);


    //? buttons box
    App->buttonsbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,50);
    gtk_box_pack_start(GTK_BOX(App->vbox),App->buttonsbox,TRUE,TRUE,0);

    //? confirm button
    App->confirmButton = gtk_button_new_with_label("Valider");
    gtk_box_pack_start(GTK_BOX(App->buttonsbox),App->confirmButton,TRUE,TRUE,0);
    gtk_widget_set_name(App->confirmButton,"confirm_button");
    g_signal_connect(G_OBJECT(App->confirmButton),"clicked",G_CALLBACK(handleAddIncomeConfirm),(gpointer)compApp);


    //? cancel button
    App->cancelButton = gtk_button_new_with_label("Annuler");
    gtk_box_pack_start(GTK_BOX(App->buttonsbox), App->cancelButton, TRUE, TRUE, 0);
    gtk_widget_set_name(App->confirmButton, "cancel_button");
    g_signal_connect(G_OBJECT(App->cancelButton),"clicked",gtk_window_close,App->window);

    //! à faire :  vérifier que l'entry est numeric , ajouter la date

    compApp->incomeaddwindow = App;
    gtk_widget_show_all(App->window);
}