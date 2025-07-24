//FormAI DATASET v1.0 Category: Database querying ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    const char *createTableSQL = "CREATE TABLE STUDENTS(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL, GRADE INT NOT NULL)";
    rc = sqlite3_exec(db, createTableSQL, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    const char *insertSQL = "INSERT INTO STUDENTS (ID, NAME, AGE, GRADE) VALUES (1, 'John Doe', 18, 72), (2, 'Jane Doe', 19, 81), (3, 'Jack Smith', 20, 93)";
    rc = sqlite3_exec(db, insertSQL, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    const char *selectSQL = "SELECT * FROM STUDENTS WHERE AGE > 18 AND GRADE > 75";
    rc = sqlite3_exec(db, selectSQL, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Query executed successfully\n");
    }

    sqlite3_close(db);
    return 0;
}