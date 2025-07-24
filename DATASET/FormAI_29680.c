//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* The callback function for querying the database */
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    
    /* Open the database */
    rc = sqlite3_open("example.db", &db);
    if(rc){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
    }
    
    /* Create the table */
    char *sql = "CREATE TABLE IF NOT EXISTS employees ( id INT PRIMARY KEY NOT NULL, name TEXT NOT NULL, age INT NOT NULL, salary REAL NOT NULL );";
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully\n");
    }
    
    /* Insert some data */
    sql = "INSERT INTO employees (id,name,age,salary) VALUES (1, 'John Smith', 35, 55000.0 ); "
          "INSERT INTO employees (id,name,age,salary) VALUES (2, 'Jane Doe', 28, 46000.0 ); "
          "INSERT INTO employees (id,name,age,salary) VALUES (3, 'Mark Johnson', 42, 72000.0 ); "
          "INSERT INTO employees (id,name,age,salary) VALUES (4, 'Sarah Lee', 31, 61000.0 ); "
          "INSERT INTO employees (id,name,age,salary) VALUES (5, 'Alex Kim', 45, 87000.0 ); ";
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Data inserted successfully\n");
    }
    
    /* Query the database */
    sql = "SELECT * from employees;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Query executed successfully\n");
    }
    
    /* Close the database */
    sqlite3_close(db);
    
    return 0;
}