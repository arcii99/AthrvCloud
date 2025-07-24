//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> // This library is required for SQLite

int main(int argc, char* argv[]) {
    sqlite3* db; // The database handle
    int rc; // Return code from the database functions
    char* err_msg = NULL; // Error message string from the database functions

    // Open the database
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Unable to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a simple SELECT statement
    const char* sql = "SELECT * FROM users";
    rc = sqlite3_exec(db, sql, NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SELECT statement failed: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}