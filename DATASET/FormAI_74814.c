//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]){
    sqlite3 *db;
    char *err_msg = 0;
    char *sql;
    int rc;
    
    rc = sqlite3_open("example.db", &db);
    
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    sql = "CREATE TABLE IF NOT EXISTS Cars(Id INT PRIMARY KEY, Name TEXT, Price INT)";
    
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    sql = "INSERT INTO Cars VALUES(1, 'Audi', 52642);"
          "INSERT INTO Cars VALUES(2, 'Mercedes', 57127);"
          "INSERT INTO Cars VALUES(3, 'Skoda', 9000);"
          "INSERT INTO Cars VALUES(4, 'Volvo', 29000);"
          "INSERT INTO Cars VALUES(5, 'Bentley', 350000);"
          "INSERT INTO Cars VALUES(6, 'Citroen', 21000);"
          "INSERT INTO Cars VALUES(7, 'Hummer', 41400);"
          "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";
    
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if(rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    } 
    
    sql = "SELECT * FROM Cars WHERE Price < 30000 ORDER BY Price DESC;";
    
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_close(db);
    
    return 0;
}