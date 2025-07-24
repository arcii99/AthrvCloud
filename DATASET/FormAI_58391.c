//FormAI DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void) {
    sqlite3 *db;
    char *sql_statement;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("database.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sql_statement = "SELECT * FROM table WHERE column1 == ? AND column2 > ?;";
    rc = sqlite3_prepare_v2(db, sql_statement, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_bind_int(stmt, 1, 5); // bind integer value to first parameter
    rc = sqlite3_bind_double(stmt, 2, 3.14); // bind double value to second parameter

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Value1: %d, Value2: %s\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}