#ifndef __DBCONNECT_H__
#define __DBCONNECT_H__
#include<mysql/mysql.h>
#include "dbconnectioninfo.h"
#include <string.h>
#include "usersList.h"
void get_users(gpointer data){
    MainWindow* App = (MainWindow*)data;
    int totalUsers=0;
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "SELECT * FROM users");
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }else{
            res = mysql_use_result(conn);
            /* output table name */
            printf("MySQL Tables in mysql database:\n");
            while ((row = mysql_fetch_row(res)) != NULL){
                printf("%s \n", row[1]);
                strcpy(App->users[totalUsers],row[1]);
                totalUsers++;
        }
        App->numberOfUsers = totalUsers; 
        // handle_users((gpointer)App);
        g_print("total number of users : %d",App->numberOfUsers);
    }}
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_free_result(res);
    mysql_close(conn);
}

void add_new_user(char *user,char *password){
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    if(mysql_real_connect(conn,DBSRV,DBUID,DBPWD,DBNAME,0,NULL,0)){
        sprintf(query, " insert into users(name,password) values('%s','%s')",user,password);
        if(mysql_query(conn,query)){
            g_print("ERROR : %d", mysql_errno(conn));
        }   
    }else{
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_close(conn);
}
#endif