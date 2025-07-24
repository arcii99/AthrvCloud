//FormAI DATASET v1.0 Category: Database querying ; Style: content
#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char** argv) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql;
    int rc;

    /* Open the database */
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Prepare the SQL statement */
    sql = "SELECT * FROM users WHERE age > ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Bind a parameter to the statement */
    sqlite3_bind_int(stmt, 1, 18);

    /* Execute the query */
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*) sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("user id=%d, name=%s, age=%d\n", id, name, age);
    }

    /* Finalize the statement and close the database */
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}