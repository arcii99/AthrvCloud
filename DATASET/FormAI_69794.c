//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USERNAME "root"
#define PASSWORD "password"
#define DATABASE "my_database"

int main() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, SERVER,
                            USERNAME, PASSWORD,
                            DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char query[200] = "SELECT * FROM my_table WHERE color = 'red' AND price < 10";

    if (mysql_query(conn, query)) {

        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("Item ID: %s\n", row[0]);
        printf("Name: %s\n", row[1]);
        printf("Color: %s\n", row[2]);
        printf("Price: %s\n", row[3]);
    }

    mysql_free_result(res);

    mysql_close(conn);

    return 0;
}