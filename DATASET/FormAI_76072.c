//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS ""
#define DB_NAME "mydatabase"

int main(int argc, char **argv)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char query[200];
    strcpy(query, "SELECT * FROM users WHERE age > 25");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    printf("ID\tName\t\tAge\tCity\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\t%s\t\t%s\t%s\n", row[0], row[1], row[2], row[3]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}