//FormAI DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *servername = "localhost";
    char *username = "root";
    char *password = "mypassword";
    char *database = "mydatabase";

    conn = mysql_init(NULL);
    if(conn == NULL) {
        printf("Error:Couldn't initiate MySQL connection!\n");
        exit(1);
    }

    if(mysql_real_connect(conn, servername, username, password, database, 0, NULL, 0) == NULL) {
        printf("Error:Couldn't connect to MySQL database!\n");
        exit(1);
    }

    if(mysql_query(conn, "SELECT * FROM mytable")) {
        printf("Error:Couldn't execute the query!\n");
        exit(1);
    }

    res = mysql_use_result(conn);

    printf("Query results:\n");
    while((row = mysql_fetch_row(res)) != NULL) {
        printf("ID: %s, Name: %s, Age: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}