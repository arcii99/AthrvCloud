//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void show_query_results(sqlite3_stmt *stmt) {
    int result;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char *first_name = sqlite3_column_text(stmt, 0);
        const unsigned char *last_name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("First Name: %s\nLast Name: %s\nAge: %d\n\n", first_name, last_name, age);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s DATABASE_FILE\n", argv[0]);
        return 1;
    }

    sqlite3 *db;
    if (sqlite3_open(argv[1], &db) == SQLITE_OK) {
        printf("Opened database successfully\n");

        char *query = "SELECT * FROM users WHERE age >= ?";
        sqlite3_stmt *stmt;
        if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
            int min_age = 18;
            sqlite3_bind_int(stmt, 1, min_age);
            printf("Executing query: %s\n", query);
            show_query_results(stmt);
        } else {
            printf("Failed to prepare query: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
    } else {
        printf("Failed to open database: %s\n", sqlite3_errmsg(db));
    }

    return 0;
}