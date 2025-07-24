//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv)
{
    // Initialize database connection
    MYSQL *conn = mysql_init(NULL);

    // Connect to database
    if (mysql_real_connect(conn, "localhost", "user", "password", "database", 0, NULL, 0) == NULL) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return 1;
    }

    // Set up SQL query and execute it
    char *query = "SELECT * FROM customers WHERE age > 25";
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        return 1;
    }

    // Get results and print them out
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error getting result: %s\n", mysql_error(conn));
        return 1;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // Clean up and close database connection
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}