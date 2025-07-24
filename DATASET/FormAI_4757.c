//FormAI DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define callback function to print the returned values
static int callback(void *data, int argc, char **argv, char **col_name) {
    int i;
    printf("\n");
    for(i=0; i<argc; i++) {
        printf("%s: %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main(void) {
    // Declare variables for sqlite3 object and error message
    sqlite3 *db;
    char *err_msg = 0;

    // Open the database
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table called 'students'
    char *sql = "CREATE TABLE students ("
                "id INTEGER PRIMARY KEY,"
                "name TEXT NOT NULL,"
                "age INTEGER NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Insert some example data
    sql = "INSERT INTO students (id, name, age) VALUES "
          "(1, 'John Doe', 18), "
          "(2, 'Jane Smith', 21), "
          "(3, 'Bob Johnson', 19), "
          "(4, 'Samantha Lee', 22);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query the database
    sql = "SELECT * FROM students WHERE age > 20;";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Close the database
    sqlite3_close(db);
    return 0;
}