//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// callback function to print results
int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char *)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // open the database file
    rc = sqlite3_open("example.db", &db);

    // if failed to open database file
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    // create SQL statement
    char *sql = "SELECT * FROM users WHERE age > 18;";

    // execute SQL statement
    rc = sqlite3_exec(db, sql, callback, (void*) "Result:", &zErrMsg);

    // if failed to execute SQL statement
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Query executed successfully\n");
    }

    // close database
    sqlite3_close(db);
    return 0;
}