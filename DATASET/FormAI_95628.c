//FormAI DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define a function to display the queried data
static int display_data(void *data, int argc, char **argv, char **column_names) {
    // Print out the column names
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", column_names[i], argv[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;

    // Open the database file and create a database object
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Define the query to execute
    char *query = "SELECT * FROM employees WHERE salary > 50000;";

    // Execute the query
    rc = sqlite3_exec(db, query, display_data, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Close the database
    sqlite3_close(db);
    return EXIT_SUCCESS;
}