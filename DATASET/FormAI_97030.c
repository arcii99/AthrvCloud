//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the database file path
#define DB_FILE "./example.db"

// Define the SQL query to create the table
#define CREATE_TABLE_SQL \
    "CREATE TABLE IF NOT EXISTS people ( \
        id INTEGER PRIMARY KEY AUTOINCREMENT, \
        name TEXT NOT NULL, \
        age INTEGER NOT NULL, \
        email TEXT UNIQUE NOT NULL \
    );"

// Define the SQL query to insert records
#define INSERT_RECORD_SQL \
    "INSERT INTO people (name, age, email) VALUES (?, ?, ?);"

// Define the SQL query to select all records
#define SELECT_ALL_SQL \
    "SELECT id, name, age, email FROM people;"

// Define the callback function for the select query
int select_callback(void *data, int argc, char **argv, char **col_names)
{
    int i;
    printf("\n");
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_names[i], argv[i]);
    }
    printf("-------------------------------------\n");
    return 0;
}

int main()
{
    int rc;
    sqlite3 *db;

    // Open the database
    rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create the table if it doesn't exist
    rc = sqlite3_exec(db, CREATE_TABLE_SQL, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Insert some data into the table
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, INSERT_RECORD_SQL, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    sqlite3_bind_text(stmt, 1, "John Smith", -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, 25);
    sqlite3_bind_text(stmt, 3, "john.smith@example.com", -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    // Select all data from the table
    rc = sqlite3_exec(db, SELECT_ALL_SQL, select_callback, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Clean up
    sqlite3_close(db);
    return 0;
}