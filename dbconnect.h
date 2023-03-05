#include<mysql/mysql.h>
#include "dbconnectioninfo.h"
#include "string.h"
#include "usersList.h"
#include "userStruct.h"
#ifndef __DBCONNECT_H__
#define __DBCONNECT_H__

void get_users(gpointer data);

void add_new_user(char *user,char *password);
void deleteUser(char name[]) ;
void get_selected_user(gpointer data);
int user_exist(char name[]);
int verify_password(char *name,char *password);
// void get_last_user_id(gpointer data);
void get_total_depenses_and_income(gpointer data);
void get_user_id(gpointer data);
#endif