//FormAI DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function that prints error messages
static int errorHandler(void *data, const char *errorMessage){
    fprintf(stderr, "Error: %s\n", errorMessage);
    return 0;
}

int main(){
    sqlite3 *db; // Pointer to SQLite database
    char *errMessage = 0; // Error message
    int rc; // Return code

    // Open connection to database
    rc = sqlite3_open("test.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    // SQL query statement
    char *sql = "SELECT * FROM EMPLOYEE";

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, errorHandler, 0, &errMessage);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }

    // Close connection to database
    sqlite3_close(db);
    return 0;
}