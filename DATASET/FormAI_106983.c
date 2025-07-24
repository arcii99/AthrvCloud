//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function for selecting data
static int select_callback(void *data, int argc, char **argv, char **az_col_name) {
    int i;
    *(int*)data = 1;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", az_col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    int done = 0;

    // Open the database
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create table if it does not exist already
    char *sql = "CREATE TABLE IF NOT EXISTS user (id INT, name TEXT, age INT);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Insert data into table
    sql = "INSERT INTO user (id, name, age) VALUES (1, 'John Doe', 25), (2, 'Jane Doe', 30);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Select data from table
    sql = "SELECT * FROM user;";
    rc = sqlite3_exec(db, sql, select_callback, &done, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Wait for async operations to finish
    while (!done) {
        rc = sqlite3_exec(db, NULL, NULL, NULL, NULL);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return 1;
        }
    }

    // Close the database
    sqlite3_close(db);
    return 0;
}