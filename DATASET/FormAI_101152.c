//FormAI DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn; // declare a MySQL connection object
    MYSQL_RES *res; // declare a MySQL result set object
    MYSQL_ROW row; // declare a MySQL row object

    char *server = "localhost"; // database server address
    char *user = "root"; // database username
    char *password = "password"; // database password
    char *database = "mydb"; // database name

    conn = mysql_init(NULL); // initialize the MySQL object
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) { // connect to the database server
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char *query = "SELECT * FROM persons"; // the SQL query
    if (mysql_query(conn, query)) { // execute the query
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn); // store the query result in a MySQL result set
    while ((row = mysql_fetch_row(res)) != NULL) { // iterate through the result set rows
        printf("%s %s %s\n", row[0], row[1], row[2]); // print the row values
    }

    mysql_free_result(res); // free the result set object
    mysql_close(conn); // close the connection

    return 0;
}