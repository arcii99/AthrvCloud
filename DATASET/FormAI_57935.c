//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "mydatabase.db"

/* Callback function to print query results */
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    NotUsed = 0;
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *errMsg = NULL;
    int rc;

    /* Open the database */
    rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Create the table */
    const char *createStmt = "CREATE TABLE IF NOT EXISTS people ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "name TEXT NOT NULL, "
                             "age INT NOT NULL, "
                             "email TEXT NOT NULL UNIQUE); ";
    rc = sqlite3_exec(db, createStmt, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: '%s'\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    /* Insert some data */
    const char *insertStmt = "INSERT INTO people (name, age, email) VALUES ('John Doe', 25, 'john.doe@example.com'), "
                             "('Jane Doe', 28, 'jane.doe@example.com'), "
                             "('Jacob Smith', 30, 'jacob.smith@example.com'), "
                             "('Emily Jones', 23, 'emily.jones@example.com')";
    rc = sqlite3_exec(db, insertStmt, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: '%s'\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    /* Query the database */
    const char *selectStmt = "SELECT * FROM people WHERE age > 25";
    rc = sqlite3_exec(db, selectStmt, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: '%s'\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    /* Update some data */
    const char *updateStmt = "UPDATE people SET age = 26 WHERE name = 'John Doe'";
    rc = sqlite3_exec(db, updateStmt, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: '%s'\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    /* Delete some data */
    const char *deleteStmt = "DELETE FROM people WHERE name = 'Emily Jones'";
    rc = sqlite3_exec(db, deleteStmt, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: '%s'\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    /* Close the database */
    sqlite3_close(db);
    return 0;
}