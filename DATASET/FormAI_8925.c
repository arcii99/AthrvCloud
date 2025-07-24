//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <string.h>

// Callback function for SELECT query
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

// Function to handle SELECT query asynchronously
int handleAsyncSelectQuery(sqlite3* db, const char* sql) {
    // Initialize async data structure
    typedef struct {
        bool isReady;
        int rc;
    } asyncData;
    asyncData data = {false, -1};

    // Create callback function for select query
    sqlite3_exec(db, sql, callback, &data, NULL);
    
    // Wait for callback to mark data as ready
    while (!data.isReady);
    
    return data.rc;
}

// Main function for program
int main() {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    // Attempt to open the database file
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(1);
    }

    // Create a table
    const char* createTableSql = "CREATE TABLE IF NOT EXISTS test ("  \
        "id INTEGER PRIMARY KEY," \
        "name TEXT NOT NULL," \
        "value REAL);";

    rc = sqlite3_exec(db, createTableSql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    }

    // Insert data into table
    const char* insertSql = "INSERT INTO test (name,value) VALUES ('foo',1.23);";
    rc = sqlite3_exec(db, insertSql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    }

    // Query data asynchronously
    const char* selectSql = "SELECT * FROM test;";
    rc = handleAsyncSelectQuery(db, selectSql);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}