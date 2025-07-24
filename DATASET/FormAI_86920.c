//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* errorMessage = NULL;
    int rc;
    
    // Open connection to database
    rc = sqlite3_open("mydatabase.db", &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    else {
        printf("Connection to the database has been established successfully!\n");
    }
    
    // Create a table
    char* createTableSQL = "CREATE TABLE IF NOT EXISTS Users(id INTEGER PRIMARY KEY, name TEXT, age INT, email TEXT);";
    rc = sqlite3_exec(db, createTableSQL, NULL, 0, &errorMessage);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return 1;
    }
    else {
        printf("Table has been created successfully!\n");
    }
    
    // Insert data into the table
    char* insertDataSQL1 = "INSERT INTO Users(name, age, email) VALUES('John', 32, 'john@example.com');";
    rc = sqlite3_exec(db, insertDataSQL1, NULL, 0, &errorMessage);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return 1;
    }
    
    char* insertDataSQL2 = "INSERT INTO Users(name, age, email) VALUES('Mary', 28, 'mary@example.com');";
    rc = sqlite3_exec(db, insertDataSQL2, NULL, 0, &errorMessage);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return 1;
    }
    
    char* insertDataSQL3 = "INSERT INTO Users(name, age, email) VALUES('Bob', 45, 'bob@example.com');";
    rc = sqlite3_exec(db, insertDataSQL3, NULL, 0, &errorMessage);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return 1;
    }
    
    // Query the database
    char* querySQL = "SELECT * FROM Users;";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, querySQL, -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    printf("----------\n");
    printf("| ID | Name | Age | Email |\n");
    printf("----------\n");
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char* email = sqlite3_column_text(stmt, 3);
        
        printf("| %d | %s | %d | %s |\n", id, name, age, email);
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}