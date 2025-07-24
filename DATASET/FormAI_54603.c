//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
    // Open a connection to the database
    sqlite3 *db;
    int rc = sqlite3_open("jokes.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Joke database connection established!\n");
    }

    // Define the SQL query to retrieve a joke
    const char *sql = "SELECT joke FROM jokes ORDER BY RANDOM() LIMIT 1;";
    sqlite3_stmt *stmt;

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Can't prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute the statement
    if (sqlite3_step(stmt) != SQLITE_ROW) {
        fprintf(stderr, "No jokes found!\n");
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    } else {
        // Print the joke retrieved from the database
        printf("%s\n", sqlite3_column_text(stmt, 0));
    }

    // Finalize the statement and close the database connection
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}