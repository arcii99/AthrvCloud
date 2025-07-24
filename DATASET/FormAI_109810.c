//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> // SQLite library

int main(int argc, char** argv) {
    sqlite3* db; // Pointer to SQLite database
    sqlite3_stmt* stmt; // SQLite statement object
    const char* query = "SELECT name, age, gender FROM people WHERE id = ?"; // Placeholder query
    int id = 1; // Example ID to query
    
    int rc = sqlite3_open("example.db", &db); // Open SQLite database
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error opening SQLite database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL); // Prepare the query statement
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing SQLite statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_bind_int(stmt, 1, id); // Bind the integer ID to the statement
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error binding integer to SQLite statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_step(stmt); // Execute the query and loop through results
    while(rc == SQLITE_ROW) {
        const char* name = sqlite3_column_text(stmt, 0); // Get the name column as a string
        int age = sqlite3_column_int(stmt, 1); // Get the age column as an integer
        const char* gender = sqlite3_column_text(stmt, 2); // Get the gender column as a string
        
        printf("Name: %s | Age: %d | Gender: %s\n", name, age, gender); // Print result
        
        rc = sqlite3_step(stmt); // Get the next row
    }
    if(rc != SQLITE_DONE) { // Check if there was an error before finalizing the statement
        fprintf(stderr, "Error executing SQLite statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_finalize(stmt); // Finalize the SQLite statement
    sqlite3_close(db); // Close the SQLite database
    
    return 0;
}