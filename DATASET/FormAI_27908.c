//FormAI DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <sqlite3.h> 

static int callback(void *NotUsed, int argc, char **argv, char **azColName) { 
    int i; 
    for(i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
    printf("\n"); 
    return 0; 
} 

int main(int argc, char* argv[]) { 
    if (argc < 2) { 
        printf("Usage: %s DATABASE\n", argv[0]); 
        return 1; 
    } 
    sqlite3 *db; 
    char *zErrMsg = 0; 
    int rc; 
    rc = sqlite3_open(argv[1], &db); 
    if (rc) { 
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db)); 
        sqlite3_close(db); 
        return 1; 
    } 
    char *sql; 
    sql = "SELECT * FROM Employees WHERE Age > 30;"; 
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg); 
    if (rc != SQLITE_OK) { 
        fprintf(stderr, "SQL error: %s\n", zErrMsg); 
        sqlite3_free(zErrMsg); 
    } 
    sqlite3_close(db); 
    return 0; 
}