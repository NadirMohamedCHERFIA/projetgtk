#ifndef __COMPOSED_H__
#define __COMPOSED_H__
#include "widgets.h"
#include "deleteConfirmForm.h"
#define ADMINPASSWORD "adminadmin"
typedef struct composedWindow
{
    int id;
    char name[100];
    double total_depenses;
    double total_income;

    char date_formated[20];
    char date_string[40];

    GtkWidget *dialog;
    MainWindow *App;
    signUpWindow *signup;
    newUserWindow *newUser;
    dashboardWindow *dashboard;
    userNamePassword *userDelteConfirmation;

} composedWindow;
#endif