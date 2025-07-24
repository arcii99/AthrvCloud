//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Declare the callback function that will be triggered for each row of the result set
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Open the database file
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    char *sql_create = "CREATE TABLE COMPANY("
                       "ID INT PRIMARY KEY NOT NULL,"
                       "NAME TEXT NOT NULL,"
                       "AGE INT NOT NULL,"
                       "ADDRESS CHAR(50),"
                       "SALARY REAL);";
    rc = sqlite3_exec(db, sql_create, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Insert some values into the table
    char *sql_insert = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                       "VALUES (1, 'Paul', 32, 'California', 20000.0);"
                       "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                       "VALUES (2, 'Allen', 25, 'Texas', 15000.0);"
                       "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                       "VALUES (3, 'Teddy', 23, 'Norway', 20000.0);"
                       "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                       "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.0);";
    rc = sqlite3_exec(db, sql_insert, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Select all rows from the table
    char *sql_select = "SELECT * FROM COMPANY;";
    rc = sqlite3_exec(db, sql_select, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Select rows with a specific condition
    char *sql_select2 = "SELECT * FROM COMPANY WHERE SALARY > 25000;";
    rc = sqlite3_exec(db, sql_select2, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Update a row
    char *sql_update = "UPDATE COMPANY SET SALARY = 50000 WHERE ID = 1;";
    rc = sqlite3_exec(db, sql_update, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Delete a row
    char *sql_delete = "DELETE FROM COMPANY WHERE ID = 2;";
    rc = sqlite3_exec(db, sql_delete, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Close the database connection
    sqlite3_close(db);
    return 0;
}