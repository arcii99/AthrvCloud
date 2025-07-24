//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function to print query results
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    printf("%s: ", (const char*) data);
    for(i=0; i<argc; i++) {
        printf("%s = %s\t", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Query result";
    
    // Open database
    rc = sqlite3_open("example.db", &db);
    if(rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully!\n");
    }
    
    // Create table
    sql = "CREATE TABLE STUDENT("
          "ID INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "AGE            INT     NOT NULL);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully!\n");
    }

    // Insert data
    sql = "INSERT INTO STUDENT (ID, NAME, AGE) VALUES (1, 'John', 20); "
          "INSERT INTO STUDENT (ID, NAME, AGE) VALUES (2, 'Sarah', 21); "
          "INSERT INTO STUDENT (ID, NAME, AGE) VALUES (3, 'Mike', 19); "
          "INSERT INTO STUDENT (ID, NAME, AGE) VALUES (4, 'Emily', 22); ";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Records created successfully!\n");
    }

    // Select all data
    sql = "SELECT * FROM STUDENT;";

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    
    // Close database
    sqlite3_close(db);
    
    return 0;
}