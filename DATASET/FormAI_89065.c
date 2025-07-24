//FormAI DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "myDB"

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    const char *server = SERVER;
    const char *user = USER;
    const char *password = PASSWORD;
    const char *database = DATABASE;
    
    conn = mysql_init(NULL);
    
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char *query_string = "SELECT name, age FROM people";
    if (mysql_query(conn, query_string)) 
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    
    res = mysql_use_result(conn);
    
    printf("Name | Age\n");
    while ((row = mysql_fetch_row(res))) 
    {
        printf("%s | %s\n", row[0], row[1]);
    }
    
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}