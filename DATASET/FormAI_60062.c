//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db; // declare a pointer to SQLite database object
    char *errMsg = 0; // initialize errors to 0
    sqlite3_stmt *stmt; // declare a pointer to a prepared statement object

    // open the database
    int rc = sqlite3_open("myDatabase.db", &db);

    // check for errors in opening the database
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // prepare the query statement
    rc = sqlite3_prepare_v2(db, "SELECT * FROM customers WHERE country = ?", -1, &stmt, NULL);

    // check for errors in preparing the statement
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // bind parameters to the statement
    rc = sqlite3_bind_text(stmt, 1, "USA", -1, SQLITE_STATIC);

    // check for errors in binding parameters
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot bind parameters: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // execute the statement and print the results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // get the values from the result set
        int id = sqlite3_column_int(stmt, 0);
        char *name = (char *) sqlite3_column_text(stmt, 1);
        char *country = (char *) sqlite3_column_text(stmt, 2);
        char *email = (char *) sqlite3_column_text(stmt, 3);

        // print the values to the console
        printf("ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Country: %s\n", country);
        printf("Email: %s\n", email);
    }

    // finalize and close everything
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}