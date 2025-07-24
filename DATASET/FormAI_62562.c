//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h> // We will be using SQLite3 as our database management system

int main(int argc, char *argv[]) {
    sqlite3 *db; // Declare a pointer to a sqlite3 database
    char *errMsg = 0; // Initialize the error message to NULL
    int rc; // Declare a variable to hold the return code of database queries

    // Open the database or create a new one if it doesn't exist
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) { // If the database opening fails
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("Database opened successfully!\n");

    // Create a new table
    char *sql = "CREATE TABLE STUDENTS("
                "ID INT PRIMARY KEY     NOT NULL,"
                "NAME           TEXT    NOT NULL,"
                "AGE            INT     NOT NULL,"
                "GPA            REAL);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully!\n");
    }

    // Insert some data into the table
    sql = "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (1, 'John Doe', 20, 3.8); "
          "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (2, 'Jane Doe', 22, 3.9); "
          "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (3, 'Bob Smith', 19, 3.5); ";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Data inserted successfully!\n\n");
    }

    // Query the database and print the results
    sql = "SELECT * FROM STUDENTS WHERE AGE < 21 ORDER BY GPA DESC; ";

    // Define a callback function to print the query results
    int callback(void *data, int argc, char **argv, char **colName) {
        int i;
        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}