//FormAI DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* errmsg = NULL;
    int ret_val = 0;

    // Open database
    if (sqlite3_open("test.db", &db) != SQLITE_OK) {
        printf("Failed to open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Define query to retrieve data from the database
    const char* query = "SELECT * FROM students WHERE age > ? ORDER BY age DESC";

    // Prepare the query
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Failed to prepare query: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Bind the parameter 'age'
    int age = 20;
    if (sqlite3_bind_int(stmt, 1, age) != SQLITE_OK) {
        printf("Failed to bind parameter: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Execute the query
    while ((ret_val = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve the data from the results set
        int id = sqlite3_column_int(stmt, 0);
        char* name = (char*)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        float grade = sqlite3_column_double(stmt, 3);

        // Print the data
        printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", id, name, age, grade);
    }

    // Finalize the query
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        printf("Failed to finalize query: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Close the database connection
    if (sqlite3_close(db) != SQLITE_OK) {
        printf("Failed to close database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    return 0;
}