//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[1000];

    conn = mysql_init(NULL);

    // Connect to database
    if (mysql_real_connect(conn, "localhost", "root", "password", "company", 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Prepare SQL query
    sprintf(query, "SELECT * FROM employee");

    // Execute query 
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Get result set
    result = mysql_store_result(conn);

    // Loop through rows in result set
    while ((row = mysql_fetch_row(result)) != NULL) {
        printf("ID: %s\n", row[0]);
        printf("Name: %s\n", row[1]);
        printf("Salary: %s\n", row[2]);
        printf("Department: %s\n", row[3]);
        printf("--------------------------\n");
    }

    // Clean up
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}