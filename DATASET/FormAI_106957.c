//FormAI DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DATABASE "test.db"

int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open(DATABASE, &db);
    if(rc){
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    else{
        fprintf(stdout, "\nOpened database successfully\n");
    }

    /* Create SQL statement */
    const char *sql = "SELECT * FROM COMPANY WHERE AGE > 25";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "\nSQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else{
        fprintf(stdout, "\nOperation done successfully\n");
    }

    /* Close database */
    sqlite3_close(db);
    return 0;
}