//FormAI DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Book;

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "root", "password", "library", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    char query[100];
    sprintf(query, "SELECT * FROM books");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES *result = mysql_use_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        Book *book = (Book*)malloc(sizeof(Book));
        book->id = atoi(row[0]);
        strcpy(book->name, row[1]);
        book->price = atof(row[2]);
        printf("Book #%d: %s - $%.2f\n", book->id, book->name, book->price);
        free(book);
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}