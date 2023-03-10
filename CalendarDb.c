#include "CalendarDb.h"
static char MONTHS[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Décembre"};
static void onCalendarChange(GtkWidget *calendar, gpointer data)
{
    composedWindow *compApp = (composedWindow *)data;
    calendarWindow *App= compApp->calendar_window;
    guint year, month, day;
    gtk_calendar_get_date(calendar, &year, &month, &day);
    char date[100];
    sprintf(App->date_formated, "%d-%02d-%02d", year, month + 1,day);
    sprintf(App->date_string, "%02d %s %d", day, MONTHS[month], year);
    sprintf(date,"Date : %s",App->date_string);
    if(compApp->opened_window ==2){
        gtk_label_set_markup(GTK_LABEL(compApp->depense_window->dateLabel), date);
    }
    else if (compApp->opened_window == 1)
    {
        gtk_label_set_markup(GTK_LABEL(compApp->incomeaddwindow->dateLabel), date);
    }

    g_print("test : %s",App->date_formated);
}
void handleCalendar(GtkWidget *butt, gpointer data){
    composedWindow *comApp = (composedWindow*)data;
    calendarWindow *App ;
    App = comApp->calendar_window;
    App->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(App->window),GTK_WIN_POS_CENTER);
    GtkWidget *titleBar;
    titleBar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(titleBar), "Modification de la date");
    gtk_window_set_titlebar(GTK_WINDOW(App->window), titleBar);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(titleBar), TRUE);
    gtk_widget_set_name(titleBar, "titleBar");

    //? box
    App->box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(App->window),App->box);

    //? calendar
    App->calendar = gtk_calendar_new();
    gtk_box_pack_start(GTK_BOX(App->box),App->calendar,TRUE,TRUE,0);
    g_signal_connect(G_OBJECT(App->calendar), "day-selected", G_CALLBACK(onCalendarChange), (gpointer)comApp);

    //? valide button
    App->button = gtk_button_new_with_label("Valider");
    gtk_box_pack_start(GTK_BOX(App->box), App->button, TRUE, TRUE, 0);
    g_signal_connect(G_OBJECT(App->button),"clicked",gtk_window_close,App->window);

    comApp->calendar_window = App;
    gtk_widget_show_all(App->window);
}