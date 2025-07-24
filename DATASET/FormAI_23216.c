//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

sqlite3* db;

int main(int argc, char *argv[]) {
    int rc = sqlite3_open("database.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    char* query = "SELECT * FROM students WHERE grade > 80";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement\n");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        char* name = sqlite3_column_text(stmt, 1);
        int grade = sqlite3_column_int(stmt, 2);

        printf("Student ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Grade: %d\n\n", grade);
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);

    return 0;
}