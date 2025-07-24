//FormAI DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
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

    //open the database connection
    rc = sqlite3_open("test.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    //create a SELECT query to retrieve all data in the database
    char *sql = "SELECT * FROM mytable";

    //execute the query
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    //close the database connection
    sqlite3_close(db);

    return 0;
}