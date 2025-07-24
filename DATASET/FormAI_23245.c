//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// This callback function will be called for each row of data the query retrieves.
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for (int i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(){
    puts("Welcome to the Happy Database Querying Program!");
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("happy_database.db", &db);

    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    else {
        puts("Database opened successfully!");
    }

    // Let's do a happy dance and run a simple database query!
    const char *sql = "SELECT * from HAPPY_PEOPLE;";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        puts("Query executed successfully! Let's see the results :)");
    }

    sqlite3_close(db);
    return 0;
}