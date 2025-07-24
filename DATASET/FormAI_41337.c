//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>

// User defined callback function to print result set
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Asynchronous query function
static void query_database(sqlite3* db, char* query, void (*callback)(void*), void* data) {
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare query: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Execute the statement asynchronously
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
        fprintf(stderr, "Cannot execute query: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Loop through the result set
    while (rc == SQLITE_ROW) {
        callback(data);
        rc = sqlite3_step(stmt);
    }

    // Free resources
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
}

void print_result(void* data) {
    printf("Result: %s\n", (const char*)data);
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char* zErrMsg = 0;
    int rc;

    // Open database
    rc = sqlite3_open(":memory:", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create table
    char* sql = "CREATE TABLE COMPANY("
                "ID INT PRIMARY KEY NOT NULL,"
                "NAME TEXT NOT NULL,"
                "AGE INT NOT NULL,"
                "ADDRESS CHAR(50),"
                "SALARY REAL);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Insert rows
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Asynchronous query example
    char* query = "SELECT * FROM COMPANY;";
    query_database(db, query, &print_result, (void*)"Completed");

    // Close database
    sqlite3_close(db);
    return 0;
}