#ifndef __SIGNUP_H__
#define __SIGNUP_H__
#include <gtk/gtk.h>
#include "widgets.h"
#include "dimensions.h"
#include "composedWindow.h"
#include "passwordHashing.h"
#include "dbconnect.h"
#include "dashboard.h"
void createSignUp(GtkWidget *button, gpointer data);
void handleBackSignUp(GtkWidget *butt, gpointer data);
void handleUserPasswordVerification(GtkWidget *butt, gpointer data);
void signup_password_error_dialog(gpointer data);
void close_dialog(gpointer data);
#endif