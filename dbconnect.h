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
#endif