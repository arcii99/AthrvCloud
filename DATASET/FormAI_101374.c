//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Callback function to retrieve query results */
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {

    sqlite3 *db;
    char *errMsg = NULL;
    int rc;

    /* Open the database */
    rc = sqlite3_open("happy_customers.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Perform a query to retrieve names and comments of happy customers */
    char *sql = "SELECT name, comment FROM happy_customers WHERE happiness_level > 8";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } 

    /* Close the database */
    sqlite3_close(db);
    return 0;
}