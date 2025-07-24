//FormAI DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Open database
    rc = sqlite3_open("example.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create table
    sql = "CREATE TABLE STUDENTS("
          "ID INT PRIMARY KEY NOT NULL,"
          "NAME TEXT NOT NULL,"
          "AGE INT NOT NULL,"
          "GPA REAL NOT NULL);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Insert data
    sql = "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (1, 'John', 20, 3.6); "
          "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (2, 'Mary', 19, 4.0); "
          "INSERT INTO STUDENTS (ID, NAME, AGE, GPA) "
          "VALUES (3, 'Peter', 22, 3.9); ";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Query data
    sql = "SELECT * from STUDENTS WHERE GPA > 3.8;";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Close database
    sqlite3_close(db);

    return 0;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}