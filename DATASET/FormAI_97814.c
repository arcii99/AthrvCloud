//FormAI DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

sqlite3 *db;

int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    char *sql; 
    char *zErrMsg = 0;
    char *query = "SELECT * FROM suspects WHERE age > 30 AND occupation = 'doctor';";
    
    int rc = sqlite3_open("detective.db", &db);
    if(rc) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return(1);
    } else {
        fprintf(stdout, "Database opened successfully!\n");
    }

    rc = sqlite3_exec(db, query, callback, 0, &zErrMsg);
  
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Query executed successfully!\n");
    }
    
    sqlite3_close(db);
    return 0;
}