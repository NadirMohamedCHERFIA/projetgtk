#ifndef __DELETECONFIRMFORM_H__
#define __DELETECONFIRMFORM_H__
#include <gtk/gtk.h>
#include "composedWindow.h"
#include "widgets.h"
#include "dimensions.h"
#include "string.h"
#include "passwordHashing.h"
#include "dbconnect.h"
#include "signUp.h"
void create_delete_confirm_form(GtkWidget *butt, gpointer data);
void handleBackDeleteForm(GtkWidget *butt, gpointer data);
void handleUserPasswordVerificationForm(GtkWidget *butt, gpointer data);
void onEntryChange(GtkWidget *ent, gpointer data);

#endif