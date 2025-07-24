//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// callback function for SQLite query execution
static int callback(void *data, int argc, char **argv, char **colNames) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    sqlite3 *db;
    char *errMessage = 0;
    int rc;

    // open connection to the database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    // create table
    char *sqlCreateTable = "CREATE TABLE IF NOT EXISTS ExampleTable (ID INT PRIMARY KEY NOT NULL, "
        "Name TEXT NOT NULL, Age INT NOT NULL, City TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlCreateTable, 0, 0, &errMessage);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // insert data
    char *sqlInsert = "INSERT INTO ExampleTable (ID, Name, Age, City) VALUES "
        "(1, 'John', 25, 'New York'), "
        "(2, 'Sarah', 30, 'London'), "
        "(3, 'Tom', 40, 'Los Angeles'), "
        "(4, 'Lisa', 35, 'Paris')";
    rc = sqlite3_exec(db, sqlInsert, 0, 0, &errMessage);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Data inserted successfully\n");
    }

    // select data
    char *sqlSelect = "SELECT * FROM ExampleTable WHERE Age > 30";
    rc = sqlite3_exec(db, sqlSelect, callback, 0, &errMessage);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMessage);
        sqlite3_free(errMessage);
    }

    // close connection to the database
    sqlite3_close(db);
    
    return 0;
}