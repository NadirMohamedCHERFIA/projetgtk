#include "dbconnect.h"
void get_users(gpointer data)
{
    composedWindow *compApp = (composedWindow *)data;
    newUserWindow *App;
    App = compApp->newUser;
    int totalUsers = 0;
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "SELECT * FROM users ORDER BY name");
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            printf("MySQL Tables in mysql database:\n");
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                printf(" name :%s \n", row[1]);
                strcpy(compApp->App->users[totalUsers], row[1]);
                totalUsers++;
            }
            compApp->App->numberOfUsers = totalUsers;
            g_print("total number of users : %d", compApp->App->numberOfUsers);
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_free_result(res);
    mysql_close(conn);
}


int user_exist(char name[]){
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "SELECT * FROM users where name ='%s' ",name);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            printf("MySQL Tables in mysql database:\n");
            if(mysql_fetch_row(res)!=NULL){
                mysql_free_result(res);
                mysql_close(conn);
                return 1;
            }
            else{
                mysql_free_result(res);
                mysql_close(conn);
                return 0;
            }
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_free_result(res);
    mysql_close(conn);
}

int verify_password(char *name, char *password){
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    MYSQL_RES *res;
    MYSQL_ROW row;
    char returndPassword[100];
    strcpy(returndPassword,"");
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "SELECT password FROM users where name='%s'",name);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                strcpy(returndPassword,row[0]);
                g_print("db:\n");
                g_print("\ndata:%s\n",row[0]);
                g_print("verify:%s\n",password);
            }
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }

    if(strcmp(returndPassword,password)==0 && returndPassword!=""){
        mysql_free_result(res);
        mysql_close(conn);
        return 1;
    }else{
        mysql_free_result(res);
        mysql_close(conn);
        return 0;
    }
}

void add_new_user(char *user, char *password)
{
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    char query2[100];
    char query3[100];
    MYSQL_RES *res;
    MYSQL_ROW row;
    char id;
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, " insert into users(name,password) values('%s','%s')", user, password);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            sprintf(query2,"SELECT id from users ORDER BY id DESC LIMIT 1");
            if (mysql_query(conn, query2))
            {
                g_print("ERROR : %d", mysql_errno(conn));
            }else{
                res = mysql_use_result(conn);
                /* output table name */
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                    if(row[0]!=NULL){
                        id=atoi(row[0]);
                    }
                }
            }
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }

    mysql_close(conn);
}


void get_total_depenses_and_income(gpointer data){
    composedWindow *compApp = (composedWindow *)data;
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    char query2[1000];

    MYSQL_RES *res;
    MYSQL_ROW row;
    g_print("\nDATABASE ID : %d",compApp->id);
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "select sum(depense_value) from depenses where user_id =%d and depense_date LIKE '%s-__' ",compApp->id,compApp->date_formated);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            compApp->total_depenses=0;
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                if(row[0]!=NULL){
                    compApp->total_depenses = atoi(row[0]);
                }
                // g_print("\ndb total depenses : %d",atoi(row[0]));
            }
        }
        sprintf(query2, "select sum(income_value) from income where id_user =%d and income_date LIKE '%s-__'", compApp->id,compApp->date_formated);
        if (mysql_query(conn, query2))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            compApp->total_income=0;
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                if(row[0]!=NULL){
                    compApp->total_income= atoi(row[0]);
                }
                // g_print("\ndb total depenses : %d",atoi(row[0]));
            }
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_free_result(res);
    mysql_close(conn);
}

void add_income(float value, int type, int user_id, char date[], char *description){
    g_print("called");
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    // g_print("db value ! %f",value);
    // g_print("db type : %d",type);
    // g_print("user id : %d", user_id);
    // g_print("db date : %s",date);
    // g_print("db description: %s",description);

    // MYSQL_RES *res;
    // MYSQL_ROW row;
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "INSERT INTO income(income_value,id_category,id_user,income_date,description) values(REPLACE('%f',',','.'), %d, %d, '%s','%s' )", value, type, user_id, date, description);
        g_print("%s",query);

        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            g_print("income added successfully");
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    // mysql_free_result(res);
    mysql_close(conn);
}

void deleteUser(char name[]){
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query,"delete from users where name='%s'",name);
        g_print("\n%s",query);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_close(conn);
}

void get_user_id(gpointer data){
    composedWindow *compApp = (composedWindow *)data;
    MYSQL *conn = mysql_init(NULL);
    char query[1000];
    MYSQL_RES *res;
    MYSQL_ROW row;
    g_print("\nDATABASE ID : %d", compApp->id);
    if (mysql_real_connect(conn, DBSRV, DBUID, DBPWD, DBNAME, 0, NULL, 0))
    {
        sprintf(query, "select id from users where name = '%s'", compApp->name);
        if (mysql_query(conn, query))
        {
            g_print("ERROR : %d", mysql_errno(conn));
        }
        else
        {
            res = mysql_use_result(conn);
            /* output table name */
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                compApp->id = atoi(row[0]);
                // compApp->total_depenses = atoi(row[0]);
                // g_print("\ndb total depenses : %d",atoi(row[0]));
            }
        }
    }
    else
    {
        g_print("ERROR : %d", mysql_errno(conn));
    }
    mysql_free_result(res);
    mysql_close(conn);
}