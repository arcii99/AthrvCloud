//FormAI DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <database name>\n", argv[0]);
        return 1;
    }

    sqlite3 *db;
    char *err_msg = NULL;
    int rc = sqlite3_open(argv[1], &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    printf("Connected to Database\n");

    char *sql = "SELECT * FROM Products WHERE name LIKE '%s'";

    char search_query[20];
    printf("Enter the product name you want to search: ");
    scanf("%s", search_query);

    char *final_query = (char *)malloc(strlen(sql) + strlen(search_query) - 1);
    sprintf(final_query, sql, search_query);

    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, final_query, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    printf("\nHere are the search results:\n");

    int row_count = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d. %s - $%.2f\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_double(stmt, 2));
        row_count++;
    }

    if (row_count == 0) {
        printf("No products found matching search query: %s\n", search_query);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}