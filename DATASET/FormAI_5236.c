//FormAI DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    printf("%s: ", (const char *) data);
    
    for (i = 0; i < argc; i++)
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    
    printf("\n");

    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg;
    int rc;
    char *sql;
    char *data = "CALLBACK FUNCTION";

    rc = sqlite3_open("detective.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    sql = "SELECT * from CRIMES WHERE LOCATION='Baker Street';";

    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Query executed successfully\n");
    }

    sqlite3_close(db);

   return 0;
}