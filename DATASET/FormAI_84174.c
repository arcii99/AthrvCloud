//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    
    conn = mysql_init(NULL);

    if (!conn) {
        fprintf(stderr, "Failed to initialize MySQL connection\n");
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "user", "password", "database", 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL database: Error: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, "SELECT * FROM users")) {
        fprintf(stderr, "Failed to execute query: Error: %s\n", mysql_error(conn));
        exit(1);
    }
    
    result = mysql_store_result(conn);
    
    printf("Results:\n");
    
    while ((row = mysql_fetch_row(result))) {
        printf("Username: %s, Email: %s\n", row[0], row[1]);
    }
    
    mysql_free_result(result);
    mysql_close(conn);
    
    return 0;
}