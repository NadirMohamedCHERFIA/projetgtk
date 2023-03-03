#include "onQuitButton.h"
void onQuitButton(GtkWidget *butt, gpointer data)
{
    GtkWidget *dialog;
    MainWindow *App = (MainWindow *)data;
    dialog = gtk_message_dialog_new(GTK_WINDOW(App->welcome_window),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_YES_NO,
                                    "Do you really want to close the program?");
    switch (gtk_dialog_run(GTK_DIALOG(dialog)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(dialog);
        break;
    default:
        break;
    }
}
