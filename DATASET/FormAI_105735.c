//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to print the results of a database query
static int callback(void *data, int argc, char **argv, char **colName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    // Open a connection to a database
    sqlite3 *db;
    if (sqlite3_open("example.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    char *sql = "CREATE TABLE IF NOT EXISTS students (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Insert some data
    sql = "INSERT INTO students (id, name, age) VALUES (1, 'Alice', 22), (2, 'Bob', 21), (3, 'Charlie', 20);";
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Query the data
    sql = "SELECT * FROM students WHERE age > 20;";
    if (sqlite3_exec(db, sql, callback, NULL, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error querying data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Close the connection to the database
    sqlite3_close(db);
    
    return 0;
}