//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// This function will be called for each record retrieved from the database
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    // Open the database
    rc = sqlite3_open("example.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }else{
        printf("Database opened successfully\n");
    }

    // Create a new table if it doesn't already exist
    sql = "CREATE TABLE IF NOT EXISTS USERS(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL, EMAIL CHAR(50));";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        printf("Table created successfully\n");
    }

    // Insert some data into the table
    sql = "INSERT INTO USERS(ID,NAME,AGE,EMAIL) VALUES (1, 'John Doe', 30, 'johndoe@example.com'); "
          "INSERT INTO USERS(ID,NAME,AGE,EMAIL) VALUES (2, 'Jane Smith', 25, 'janesmith@example.com'); "
          "INSERT INTO USERS(ID,NAME,AGE,EMAIL) VALUES (3, 'Bob Brown', 42, 'bobbrown@example.com'); ";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        printf("Data inserted successfully\n");
    }

    // Retrieve data from the table
    sql = "SELECT * FROM USERS WHERE AGE < 40;";
    printf("Retrieving data from the database:\n");
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Close the database
    sqlite3_close(db);
    printf("Database closed successfully\n");
    return 0;
}