//FormAI DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    // Set up database connection
    sqlite3 *db;
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a query to create a table
    char *query = "CREATE TABLE customers (id INT PRIMARY KEY, name TEXT, email TEXT)";
    char *err_msg = 0;
    rc = sqlite3_exec(db, query, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Insert some data into the table
    query = "INSERT INTO customers (id, name, email) VALUES (1, 'John Doe', 'john.doe@example.com'), (2, 'Jane Smith', 'jane.smith@example.com')";
    rc = sqlite3_exec(db, query, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Execute a query to select all data from the table
    query = "SELECT * FROM customers";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Print the results of the query
    printf("ID | Name        | Email\n");
    printf("---+-------------+-------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%2d | %-11s | %s\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2));
    }

    // Clean up resources
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}