//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <sqlite3.h>

int main() {
    // Declare variables
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    // Open the database
    rc = sqlite3_open("mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create the table
    char* sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)";
    rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Insert some data
    sql = "INSERT INTO users (name, age) VALUES ('John', 25), ('Jane', 30)";
    rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting data: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Query the database
    sql = "SELECT * FROM users WHERE age > 28";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
        // Loop through the results
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* name = sqlite3_column_text(stmt, 1);
            int age = sqlite3_column_int(stmt, 2);
            printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
        }
    } else {
        fprintf(stderr, "Error querying database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}