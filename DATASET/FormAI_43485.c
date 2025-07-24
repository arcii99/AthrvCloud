//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Declare the callback function for the query result
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv){

    // Declare variables
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Open database
    rc = sqlite3_open("example.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }else{
        fprintf(stdout, "Opened database successfully\n");
    }

    // Create table
    sql = "CREATE TABLE COMPANY("
            "ID INT PRIMARY KEY     NOT NULL,"
            "NAME           TEXT    NOT NULL,"
            "AGE            INT     NOT NULL,"
            "ADDRESS        CHAR(50),"
            "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Table created successfully\n");
    }

    // Insert values
    sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
            "VALUES (1, 'Paul', 32, 'California', 20000); "
            "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
            "VALUES (2, 'Allen', 25, 'Texas', 15000); "
            "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
            "VALUES (3, 'Teddy', 23, 'Norway', NULL); "
            "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)"
            "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Values inserted successfully\n");
    }

    // Query data
    sql = "SELECT * from COMPANY;";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Data queried successfully\n");
    }

    // Close database
    sqlite3_close(db);

    return 0;
}