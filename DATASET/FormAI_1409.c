//FormAI DATASET v1.0 Category: Database querying ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

int callback(void *, int , char **, char **);

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT * FROM users WHERE age > 25;";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    } 

    sqlite3_close(db);

    return 0;
}

int callback(void *NotUsed, int argc , char **argv, char **azColName) {
    NotUsed = 0;

    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}