#ifndef __USERSLIST_H__
#define __USERSLIST_H__
#include "widgets.h"
#include "composedWindow.h"
#include "dashboard.h"
#include "signUp.h"
void handleUserClickedOn(GtkWidget *butt, gpointer data);
void handle_users(gpointer data);
void handle_adding_new_user(gpointer data);
void handleDeleteUser(GtkWidget *butt, gpointer data);
void handle_cancel_delete(GtkWidget *butt, gpointer data);
void confirm_delete_user(GtkWidget *butt, gpointer data);
#endif