//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the callback function to print out the results of a query
static int print_results(void *data, int argc, char **argv, char **col_names) {
    int i;
    for (i = 0; i < argc; ++i) {
        printf("%s = %s\n", col_names[i], argv[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *err_msg = 0;

    // Open the database
    int rc = sqlite3_open("my_database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Query the database for all rows in the "people" table
    char *sql = "SELECT * FROM people;";
    rc = sqlite3_exec(db, sql, print_results, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query the database for all rows where the age is greater than or equal to 30
    sql = "SELECT * FROM people WHERE age >= 30;";
    rc = sqlite3_exec(db, sql, print_results, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query the database for all rows where the name is "Alice"
    sql = "SELECT * FROM people WHERE name = 'Alice';";
    rc = sqlite3_exec(db, sql, print_results, 0, &err_msg);
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