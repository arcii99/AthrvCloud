//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 200

int main(int argc, char **argv)
{
    char query[MAX_QUERY_LENGTH];
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char *host = "localhost";
    char *user = "db_user";
    char *password = "password";
    char *database = "my_database";
    int port = 3306;

    // Initialize connection
    conn = mysql_init(NULL);

    // Connect to database
    if (!mysql_real_connect(conn, host, user, password, database, port, NULL, 0))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Ask user for query
    printf("Enter a SQL query to execute: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);
    query[strlen(query) - 1] = '\0'; // Remove trailing '\n'

    // Sanitize query
    mysql_real_escape_string(conn, query, query, strlen(query));

    // Execute query
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Get result set
    result = mysql_store_result(conn);

    // Print results
    printf("Results:\n");
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < mysql_num_fields(result); i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // Free resources
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}