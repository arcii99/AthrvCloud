//FormAI DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

//The callback function to print the result of the query
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(){
    sqlite3 *db; //Pointer to SQLite database
    char *errMsg = 0; //Error message
    int rc;

    /* Open database */
    rc = sqlite3_open("myDatabase.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    const char *sql = "SELECT * from myTable WHERE ID=1";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }else{
        fprintf(stdout, "Operation done successfully\n");
    }
  
    /* Close database */
    sqlite3_close(db);
    return 0;
}