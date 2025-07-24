//FormAI DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function to print out retrieved data
int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* errMsg = 0;
    int rc;
    
    // Open database
    rc = sqlite3_open("example.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    // Create table
    char* createTable = "CREATE TABLE COMPANY("
                        "ID INT PRIMARY KEY NOT NULL,"
                        "NAME TEXT NOT NULL,"
                        "AGE INT NOT NULL,"
                        "ADDRESS CHAR(50),"
                        "SALARY REAL);";
    rc = sqlite3_exec(db,createTable,0,0,&errMsg);
    if(rc!=SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);        
    }
    else {
        fprintf(stdout, "Table created successfully\n");
    }
    
    // Insert data
    char* insertData = "INSERT INTO COMPANY VALUES (1, 'Paul', 32, 'California', 20000.0); "
                       "INSERT INTO COMPANY VALUES (2, 'Allen', 25, 'Texas', 15000.0); "
                       "INSERT INTO COMPANY VALUES (3, 'Teddy', 23, 'Norway', 20000.0); "
                       "INSERT INTO COMPANY VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.0);;";
    rc = sqlite3_exec(db,insertData,0,0,&errMsg);
    if(rc!=SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);        
    }
    else {
        fprintf(stdout, "Records created successfully\n");
    }
    
    // Select data
    char* selectData = "SELECT * FROM COMPANY;";
    rc = sqlite3_exec(db,selectData,callback,(void*)"SELECTED_DATA", &errMsg);
    if(rc!=SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);        
    }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    // Close
    sqlite3_close(db);
    return 0;
}