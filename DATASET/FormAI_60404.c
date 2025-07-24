//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {

    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("example.db", &db);
    
    // Check if the database opened successfully
    if(rc) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
    
    // Prepare the SQL query
    sqlite3_stmt *stmt;
    const char *query = "SELECT name, age, location FROM people WHERE age > ?";
    rc = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
    
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing SQL query: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
    
    // Bind a value to the parameter in the query
    int min_age = 30;
    sqlite3_bind_int(stmt, 1, min_age);
    
    // Execute the query
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        // Get name, age, location from result row
        const unsigned char *name = sqlite3_column_text(stmt, 0);
        int age = sqlite3_column_int(stmt, 1);
        const unsigned char *location = sqlite3_column_text(stmt, 2);
        
        // Print the result
        printf("%s is %d years old and from %s.\n", name, age, location);
    }
    
    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return EXIT_SUCCESS;
}