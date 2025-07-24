//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("happy_database.db", &db);

    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully!\n");
    }
    printf("Creating table...\n");

    char *sql = "CREATE TABLE HAPPY_PEOPLE("  \
                 "ID INT PRIMARY KEY     NOT NULL," \
                 "NAME           TEXT    NOT NULL," \
                 "AGE            INT     NOT NULL," \
                 "OCCUPATION     CHAR(50)," \
                 "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        printf("Table created successfully!\n");
    }

    printf("Adding happy people...\n");

    sql = "INSERT INTO HAPPY_PEOPLE (ID, NAME, AGE, OCCUPATION, SALARY) " \
           "VALUES (1, 'Alice', 25, 'Developer', 65000.0 ); " \
           "INSERT INTO HAPPY_PEOPLE (ID, NAME, AGE, OCCUPATION, SALARY) " \
           "VALUES (2, 'Bob', 30, 'Designer', 80000.0 ); "     \
           "INSERT INTO HAPPY_PEOPLE (ID, NAME, AGE, OCCUPATION, SALARY)" \
           "VALUES (3, 'Charlie', 35,'Manager', 100000.0);" \
           "INSERT INTO HAPPY_PEOPLE (ID, NAME, AGE, OCCUPATION, SALARY)" \
           "VALUES (4, 'Dave', 40, 'Engineer', 120000.0 );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("People added successfully!\n");
    }

    printf("Querying happy people...\n");

    sql = "SELECT * from HAPPY_PEOPLE";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        printf("Querying complete!\n");
    }

    sqlite3_close(db);
    return 0;
}