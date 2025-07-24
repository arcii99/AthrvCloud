//FormAI DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn = mysql_init(NULL);
    if(conn == NULL) {
        fprintf(stderr, "Failed to initialize MySQL connection\n");
        exit(1);
    }

    if(mysql_real_connect(conn, "localhost", "username", "password", "database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to the database: Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Connection to database successful!\n");

    if(mysql_query(conn, "SELECT name, age FROM users WHERE age > 18")) {
        fprintf(stderr, "Failed to execute query: Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if(result == NULL) {
        fprintf(stderr, "Failed to store result set: Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    while((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] != NULL ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}