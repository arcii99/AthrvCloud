//FormAI DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){

    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for(i = 0; i<argc; i++){
       printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {

    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT * FROM Cars WHERE Price < 30000";

    rc = sqlite3_exec(db, sql, callback, "Callback function", &err_msg);

    if (rc != SQLITE_OK ) {

        fprintf(stderr, "Failed to select data\n");

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    } 

    sqlite3_close(db);

    return 0;
}