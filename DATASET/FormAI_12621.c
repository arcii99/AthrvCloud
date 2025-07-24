//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <sqlite3.h>

// Open database callback
int openDatabaseCallback(void *closed, int argc, char **argv, char **colName) {
    int i;

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {

    sqlite3 *db;
    char *errMessage = 0;
    int returnCode;
    const char *sql;
    char *query;
    const char* data = "Callback function called";

    // Open database
    returnCode = sqlite3_open("example.db", &db);

    if (returnCode) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stdout, "Database opened successfully\n");
    }

    // Create table
    sql = "CREATE TABLE IF NOT EXISTS STUDENTS("
          "ID   INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "AGE            INT     NOT NULL,"
          "ADDRESS        TEXT);";

    returnCode = sqlite3_exec(db, sql, openDatabaseCallback, 0, &errMessage);

    if (returnCode != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Insert data
    sql = "INSERT INTO STUDENTS (ID,NAME,AGE,ADDRESS) "
          "VALUES (1, 'John Doe', 22, '123 Main St, Anytown USA') "
          ",(2, 'Jane Doe', 21, '456 Main St, Anytown USA') "
          ",(3, 'Bob Smith', 23, '789 Main St, Anytown USA');";

    returnCode = sqlite3_exec(db, sql, openDatabaseCallback, 0, &errMessage);

    if (returnCode != SQLITE_OK) {
        fprintf(stderr, "Error inserting data: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Data inserted successfully\n");
    }

    // Select data
    query = "SELECT * FROM STUDENTS";
    returnCode = sqlite3_exec(db, query, openDatabaseCallback, (void*)data, &errMessage);

    if (returnCode != SQLITE_OK) {
        fprintf(stderr, "Error selecting data: %s\n", errMessage);
        sqlite3_free(errMessage);
    } else {
        fprintf(stdout, "Data selected successfully\n");
    }

    // Close database
    sqlite3_close(db);

    return 0;
}