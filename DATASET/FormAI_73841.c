//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// This function is called for each row of the query result
int callback(void* data, int argc, char** argv, char** columns) {
    // Display the data
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", columns[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    // Initialize the database
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table and insert some data
    rc = sqlite3_exec(db, "CREATE TABLE employees(id INT PRIMARY KEY, name TEXT, age INT, department TEXT);"
                           "INSERT INTO employees(id, name, age, department) VALUES(1, 'John Doe', 28, 'Sales');"
                           "INSERT INTO employees(id, name, age, department) VALUES(2, 'Jane Smith', 35, 'Marketing');"
                           "INSERT INTO employees(id, name, age, department) VALUES(3, 'Bob Johnson', 42, 'IT');",
                      NULL, NULL, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot create table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a simple query: retrieve all the data from the table
    rc = sqlite3_exec(db, "SELECT * FROM employees;", callback, NULL, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot select data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a more complex query: retrieve the names of the employees in the IT department who are older than 30
    char* sql = "SELECT name FROM employees WHERE department='IT' AND age>30;";
    rc = sqlite3_exec(db, sql, callback, NULL, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot select data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Cleanup and close the database
    rc = sqlite3_exec(db, "DROP TABLE employees;", NULL, NULL, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot drop table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}