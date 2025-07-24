//FormAI DATASET v1.0 Category: Database querying ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields;
    int i;

    // Connect to the database
    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "user", "password", "database", 0, NULL, 0);

    // Execute a simple query
    mysql_query(conn, "SELECT * FROM users");

    // Store the result set
    result = mysql_store_result(conn);

    // Get the number of fields in the result set
    num_fields = mysql_num_fields(result);

    // Print the result set
    while ((row = mysql_fetch_row(result))) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // Clean up the result set and connection
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}