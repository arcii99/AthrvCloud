//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "example.db"

int callback(void *data, int argc, char **argv, char **col_name) {
    int i;
    for (i=0; i<argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(void) {
    sqlite3 *db;
    char *error;
    char *sql;
    int rc;

    /* Open database */
    rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    /* Create table */
    sql = "CREATE TABLE IF NOT EXISTS Employees ("
          "EmployeeID INTEGER PRIMARY KEY AUTOINCREMENT, "
          "Name TEXT NOT NULL, "
          "Age INTEGER NOT NULL, "
          "City TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, NULL, 0, &error);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", error);
        sqlite3_free(error);
    }

    /* Insert data into table */
    sql = "INSERT INTO Employees (Name, Age, City) "
          "VALUES ('John Doe', 30, 'New York'), "
                 "('Jane Smith', 25, 'San Francisco'), "
                 "('Bob Johnson', 45, 'Los Angeles');";
    rc = sqlite3_exec(db, sql, NULL, 0, &error);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting data: %s\n", error);
        sqlite3_free(error);
    }

    /* Query data from table */
    sql = "SELECT * FROM Employees;";
    rc = sqlite3_exec(db, sql, callback, NULL, &error);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error querying data: %s\n", error);
        sqlite3_free(error);
    }

    /* Close database */
    sqlite3_close(db);

    return 0;
}