//FormAI DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define our global sqlite database handler
static sqlite3 *db;

// Callback function that gets called for every row that the query returns
static int callback(void *data, int argc, char **argv, char **colNames) {
    int i;
    printf("%s: ", (const char *)data); // print out the data passed in (in this case, the column to print)
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL"); // print out the column name and value for each column
    }
    return 0;
}

int main(int argc, char **argv) {
    int rc; // variable to store return codes from sqlite API calls
    
    // Open the database, creating it if necessary
    rc = sqlite3_open("my_database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    // Execute a query to create a table (if it doesn't already exist)
    char *createTableQuery = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER, email TEXT);";
    rc = sqlite3_exec(db, createTableQuery, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Execute a query to insert some data into the table
    char *insertQuery = "INSERT INTO users (name, age, email) VALUES ('John Doe', 30, 'johndoe@example.com');";
    rc = sqlite3_exec(db, insertQuery, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to insert data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Execute a query to retrieve data from the table
    char *selectQuery = "SELECT * FROM users WHERE age > 25;";
    rc = sqlite3_exec(db, selectQuery, callback, (void *)"name", NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to select data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Close the database connection
    sqlite3_close(db);
    return 0;
}