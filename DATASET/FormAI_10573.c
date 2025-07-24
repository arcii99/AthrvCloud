//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void* data, int argc, char** argv, char** azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3* db;
    char* errMsg = NULL;
    int rc;

    // Open database
    rc = sqlite3_open("test.db", &db);

    // Create table
    char* sql = "CREATE TABLE IF NOT EXISTS COMPANY("
        "ID INT PRIMARY KEY     NOT NULL,"
        "NAME           TEXT    NOT NULL,"
        "AGE            INT     NOT NULL,"
        "ADDRESS        CHAR(50),"
        "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully.\n");
    }

    // Insert record
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
        "VALUES (1, 'John Doe', 23, '123 Main St', 45000.00);";

    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Record created successfully.\n");
    }

    // Query record
    sql = "SELECT * FROM COMPANY;";

    rc = sqlite3_exec(db, sql, callback, (void*) "SELECT CALLBACK", &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Query executed successfully.\n");
    }

    sqlite3_close(db);
    return 0;
}