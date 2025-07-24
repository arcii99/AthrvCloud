//FormAI DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **col_name){
    int i;
    for(i = 0; i < argc; ++i){
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv){
    sqlite3 *db;
    char *sql;
    char *z_err_msg = 0;
    int rc;
    
    rc = sqlite3_open("example.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    
    sql = "SELECT * FROM example_table WHERE id > 1;";
    
    rc = sqlite3_exec(db, sql, callback, 0, &z_err_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", z_err_msg);
        sqlite3_free(z_err_msg);
        sqlite3_close(db);
        exit(1);
    }
    
    sqlite3_close(db);
    return 0;
}