//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* callback function to display query results */
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i=0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    /* open database */
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(1);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* create table */
    char *sql = "CREATE TABLE COMPANY("
                "ID INT PRIMARY KEY     NOT NULL,"
                "NAME           TEXT    NOT NULL,"
                "AGE            INT     NOT NULL,"
                "ADDRESS        CHAR(50),"
                "SALARY         REAL );";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    /* insert records */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
            "VALUES (1, 'Paul', 32, 'California', 20000.00); "
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
            "VALUES (2, 'Allen', 25, 'Texas', 15000.00); "
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
            "VALUES (3, 'Teddy', 23, 'Norway', 20000.00); "
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
            "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    /* select records */
    sql = "SELECT * from COMPANY WHERE SALARY > 15000.0;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    /* update record */
    sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Record updated successfully\n");
    }

    /* delete record */
    sql = "DELETE from COMPANY where ID=2;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Record deleted successfully\n");
    }
    
    /* close database */
    sqlite3_close(db);

    return 0;
}