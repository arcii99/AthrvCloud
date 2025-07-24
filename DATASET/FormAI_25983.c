//FormAI DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the callback function for the SELECT statement
static int select_callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    // Print out each row with corresponding column names
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    // Open the database file
    int rc = sqlite3_open("mydata.db", &db);

    // Check if the database was successfully opened
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a SELECT statement to retrieve all data from a specific table
    char *sql = "SELECT * FROM Customers;";

    // Execute the SELECT statement and pass the callback function
    rc = sqlite3_exec(db, sql, select_callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Close the database connection
    sqlite3_close(db);
    return 0;
}