//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function to create a database connection
sqlite3* createDatabase()
{
    sqlite3* DB;
    int exit = 0;

    // Open database
    exit = sqlite3_open("database.db", &DB);

    if (exit) {
        printf("Error creating connection to Database!\n");
        return NULL;
    }
    else {
        printf("Database connection established successfully!\n");
        return DB;
    }
}

// Function to execute SQL queries
void executeQuery(sqlite3* DB, char* query)
{
    char* message;
    int exit = 0;

    // Execute query
    exit = sqlite3_exec(DB, query, NULL, 0, &message);

    if (exit != SQLITE_OK) {
        printf("Error executing query! %s\n", message);
        sqlite3_free(message);
    }
    else {
        printf("Query executed successfully!\n");
    }
}

// Function to select data from database
void selectData(sqlite3* DB, char* query)
{
    sqlite3_stmt* statement;

    // Prepare statement
    int exit = sqlite3_prepare_v2(DB, query, -1, &statement, NULL);

    if (exit != SQLITE_OK) {
        printf("Error selecting data! Could not prepare statement!\n");
        return;
    }

    // Select data
    while (sqlite3_step(statement) == SQLITE_ROW) {
        int id = sqlite3_column_int(statement, 0);
        char* name = (char*)sqlite3_column_text(statement, 1);
        int age = sqlite3_column_int(statement, 2);
        
        printf("ID: %d\tName: %s\tAge: %d\n", id, name, age);
    }

    // Finalize statement
    sqlite3_finalize(statement);
}

// Main function
int main()
{
    sqlite3* DB = createDatabase();

    // Create table
    executeQuery(DB, "CREATE TABLE IF NOT EXISTS Users (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT, AGE INT);");

    // Insert data
    executeQuery(DB, "INSERT INTO Users (NAME, AGE) VALUES ('Alice', 25);");
    executeQuery(DB, "INSERT INTO Users (NAME, AGE) VALUES ('Bob', 32);");
    executeQuery(DB, "INSERT INTO Users (NAME, AGE) VALUES ('Charlie', 18);");

    // Select data
    selectData(DB, "SELECT * FROM Users;");

    // Close database
    sqlite3_close(DB);

    return 0;
}