//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]){
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    
    rc = sqlite3_open("test.db", &db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // create table Person
    char *sql = "CREATE TABLE Person("
                "ID INT PRIMARY KEY NOT NULL,"
                "NAME TEXT NOT NULL,"
                "AGE INT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Person table created successfully\n");
    }
    
    // insert data into Person table
    sql = "INSERT INTO Person (ID, NAME, AGE) "
          "VALUES (1, 'John', 32), (2, 'Alex', 28), (3, 'Sarah', 25), (4, 'Mike', 40);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Data inserted successfully\n");
    }
    
    // retrieve data from Person table
    sql = "SELECT * FROM Person WHERE AGE > 30;";
    char *data = "Callback function called";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &err_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    sqlite3_close(db);
    return 0;
}