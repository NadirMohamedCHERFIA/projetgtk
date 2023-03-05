#ifndef __NEWUSERCONTROLLER_H__
#define __NEWUSERCONTROLLER_H__
#include <gtk/gtk.h>
#include "string.h"
#include "widgets.h"
#include "dbconnect.h"
#include "usersList.h"
#include "composedWindow.h"

void handleBack(GtkWidget *butt, gpointer data);

void handleNewUserSubmit(GtkWidget *but,gpointer data);

void password_verification_dialog();

void user_exist_dialog();

void create_created_dialog(char *name);

int destroy_creation_dialog_info(gpointer data);

#endif