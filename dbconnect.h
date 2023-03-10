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

/*return 0 if user doesn't exist || return 1 if user does exist @params name char[]*/
int user_exist(char name[]);
int verify_password(char *name,char *password);
// void get_last_user_id(gpointer data);
void get_total_depenses_and_income(gpointer data);
void get_user_id(gpointer data);
void add_income(float value, int type, int user_id,char date[],char *description);
void add_depense(float value, int type, int user_id, char date[], char *description);
void get_user_income_details(gpointer data);
void get_user_depenses_details(gpointer data);

#endif