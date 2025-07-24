//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function to handle any database errors
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Open database
    rc = sqlite3_open("example.db", &db);
    if(rc){
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Opened database successfully\n");
    }

    // Create table
    sql = "CREATE TABLE COMPANY("
                  "ID INT PRIMARY KEY NOT NULL,"
                  "NAME TEXT NOT NULL,"
                  "AGE INT NOT NULL,"
                  "ADDRESS CHAR(50),"
                  "SALARY REAL);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully\n");
    }

    // Insert data
    sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                  "VALUES (1, 'Paul', 32, 'California', 20000.00); "
                  "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                  "VALUES (2, 'Allen', 25, 'Texas', 15000.00); "
                  "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                  "VALUES (3, 'Teddy', 23, 'Norway', 20000.00); "
                  "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                  "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Records created successfully\n");
    }

    // Query data
    sql = "SELECT * FROM COMPANY WHERE SALARY > 18000.0;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Query results:\n");
    }

    // Close database
    sqlite3_close(db);
    return 0;
}