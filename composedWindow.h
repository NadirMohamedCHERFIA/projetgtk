#ifndef __COMPOSED_H__
#define __COMPOSED_H__
#include "widgets.h"
#include "deleteConfirmForm.h"
#include "incomeAddWindow.h"
#define ADMINPASSWORD "adminadmin"
typedef struct composedWindow
{
    int id;
    char name[100];
    double total_depenses;
    double total_income;
    char date_formated[20];
    char date_string[40];
    gint first_load;
    GtkWidget *dialog;
    
    //? opened winodow 1 :  add incomes, 2: add depense@
    gint opened_window;



    MainWindow *App;
    imageWindow *imagewind;
    signUpWindow *signup;
    newUserWindow *newUser;
    dashboardWindow *dashboard;
    userNamePassword *userDelteConfirmation;
    incomeAddWindow *incomeaddwindow;
    depenseAddWindow *depense_window;
    calendarWindow *calendar_window;

} composedWindow;
#endif