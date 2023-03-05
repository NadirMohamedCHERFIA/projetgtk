#ifndef __COMPOSED_H__
#define __COMPOSED_H__
#include "widgets.h"

typedef struct composedWindow
{
    int id;
    char name[100];
    MainWindow *App;
    signUpWindow *signup;
    GtkWidget *dialog;
    newUserWindow *newUser;
    dashboardWindow *dashboard;

} composedWindow;
#endif