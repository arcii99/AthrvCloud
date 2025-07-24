//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define callback function for sqlite3_exec
int callback(void*, int, char**, char**);

int main() {

    // Declare and initialize variables
    sqlite3* db;
    char* error_msg = 0;
    int rc;
    char* sql;

    // Open database connection
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)";
    rc = sqlite3_exec(db, sql, callback, 0, &error_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot create table: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Insert data into table
    sql = "INSERT INTO users VALUES (1, 'John', 25), (2, 'Jane', 30), (3, 'Bob', 40), (4, 'Alice', 28), (5, 'Charlie', 35)";
    rc = sqlite3_exec(db, sql, callback, 0, &error_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot insert data: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query data from table
    sql = "SELECT * FROM users WHERE age > 30";
    rc = sqlite3_exec(db, sql, callback, 0, &error_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot query data: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Close database connection
    sqlite3_close(db);

    return 0;
}

// Define callback function for sqlite3_exec
int callback(void* data, int argc, char** argv, char** col_name) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}