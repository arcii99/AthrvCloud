//FormAI DATASET v1.0 Category: Database querying ; Style: thoughtful
// A unique C database querying example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the callback function to handle query result
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Open database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    // Create table Customers
    sql = "CREATE TABLE Customers (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, age INTEGER, city TEXT);";
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table Customers created successfully\n");
    }

    // Insert records into table
    sql = "INSERT INTO Customers (name, age, city) VALUES ('John', 30, 'New York');"
          "INSERT INTO Customers (name, age, city) VALUES ('Jane', 25, 'Los Angeles');"
          "INSERT INTO Customers (name, age, city) VALUES ('Tom', 40, 'Chicago');"
          "INSERT INTO Customers (name, age, city) VALUES ('Emma', 22, 'San Francisco');";
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    // Query the database
    sql = "SELECT * FROM Customers WHERE age > 25 AND city = 'New York';";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Close database
    sqlite3_close(db);

    return EXIT_SUCCESS;
}