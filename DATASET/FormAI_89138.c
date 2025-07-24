//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>

#define DB_FILE "example.db"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void select_all(sqlite3 *db){
    char *select_all_sql = "SELECT * from example";
    char *zErrMsg = 0;
    
    int rc = sqlite3_exec(db, select_all_sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void insert_example(sqlite3 *db){
    char *insert_sql = "INSERT INTO example (name, age, address) VALUES ('John', 28, '123 Cherry Lane')";
    char *zErrMsg = 0;
    
    int rc = sqlite3_exec(db, insert_sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Insert successful!\n");
    }
}

void delete_all(sqlite3 *db){
    char *delete_all_sql = "DELETE from example";
    char *zErrMsg = 0;
    
    int rc = sqlite3_exec(db, delete_all_sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("All data deleted!\n");
    }
}

int main(){
    sqlite3 *db;
    int rc = sqlite3_open(DB_FILE, &db);
    
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully\n");
    }
    
    insert_example(db);
    select_all(db);
    delete_all(db);
    select_all(db);
    
    sqlite3_close(db);
    
    return 0;
}