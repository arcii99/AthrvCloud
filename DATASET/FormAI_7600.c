//FormAI DATASET v1.0 Category: Database querying ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error: could not initialize MySQL connection.\n");
        return 1;
    }

    // Establish connection
    if (mysql_real_connect(conn, "localhost", "myuser", "mypassword", "mydatabase", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error: could not connect to MySQL database: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Prepare and execute query
    char query[1000];
    sprintf(query, "SELECT * FROM customers WHERE age > %d AND city = '%s'", atoi(argv[1]), argv[2]);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: could not execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Retrieve results
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Error: could not retrieve query results: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Query results:\n");
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("%s %s %s %s\n", row[0], row[1], row[2], row[3]);
    }

    // Cleanup
    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}