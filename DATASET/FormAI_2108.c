//FormAI DATASET v1.0 Category: Database querying ; Style: Alan Touring
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

int main(int argc, char **argv){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    
    rc = sqlite3_open("example.db", &db); // opening database connection
    
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }
    
    sql = "SELECT * from STUDENTS WHERE AGE=19;";
    
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg); // querying the database
    
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Query executed successfully\n");
    }
    
    sqlite3_close(db); // closing the database connection 
    return(0);
}