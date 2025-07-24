//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "mydatabase"

/* main function */
int main() {
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result;
    MYSQL_ROW row;
    int query_state;
    
    /* connect to the database */
    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    
    /* execute query */
    query_state = mysql_query(conn, "SELECT * FROM users WHERE age > 25");
    if (query_state) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    
    result = mysql_store_result(conn);

    /* print results */
    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s\n", row[0]);
        printf("Name: %s\n", row[1]);
        printf("Age: %s\n", row[2]);
        printf("Email: %s\n", row[3]);
        printf("------------------\n");
    }
    
    /* free memory */
    mysql_free_result(result);
    mysql_close(conn);
    
    return 0;
}