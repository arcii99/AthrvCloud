//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function to handle results of SELECT statements
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    printf("Surprise! I will now query a SQLite database for you...\n");

    // Open the database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    } else {
        printf ("Database opened successfully!\n");
    }

    // Create SELECT statement to retrieve data
    sql = "SELECT * from EMPLOYEES WHERE SALARY > 50000";

    // Execute the SELECT statement
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Operation done successfully!\n");
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}