//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void *, int, char **, char **);

int main(int argc, char *argv[]) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully\n");
    }

    char *sql = "DROP TABLE IF EXISTS COMPANY;"
                "CREATE TABLE COMPANY("
                "ID INT PRIMARY KEY NOT NULL,"
                "NAME TEXT NOT NULL,"
                "AGE INT NOT NULL,"
                "ADDRESS CHAR(50),"
                "SALARY REAL);";

    rc = sqlite3_exec(db, sql, callback, 0, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    } else {
        printf("Table created successfully\n");
    }

    char *errmsg;
    char *insert = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                   "VALUES (1, 'Paul', 32, 'California', 20000.00); "
                   "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                   "VALUES (2, 'Allen', 25, 'Texas', 15000.00); "
                   "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                   "VALUES (3, 'Teddy', 23, 'Norway', 20000.00); "
                   "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                   "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);";

    rc = sqlite3_exec(db, insert, callback, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    } else {
        printf("Records created successfully\n\n");
    }

    char *select = "SELECT * FROM COMPANY ORDER BY ID ASC;";

    rc = sqlite3_exec(db, select, callback, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    } else {
        printf("Records displayed successfully\n\n");
    }

    sqlite3_close(db);

    return 0;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {

    int i;

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}