//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sqlite3.h>

// Function to print error messages from SQLite
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
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

    // Open the database or create one if it does not exist
    rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } 

    // Create a table named "students"
    char *sql = "CREATE TABLE STUDENTS("  \
                 "ID INT PRIMARY KEY     NOT NULL," \
                 "NAME           TEXT    NOT NULL," \
                 "AGE            INT     NOT NULL," \
                 "ADDRESS        CHAR(50)," \
                 "MARKS          INT);";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);        
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Insert 3 records into the table
    char *insert1 = "INSERT INTO STUDENTS (ID,NAME,AGE,ADDRESS,MARKS) "  \
                    "VALUES (1, 'John Doe', 18, '123 Main St', 95); " \
                    "INSERT INTO STUDENTS (ID,NAME,AGE,ADDRESS,MARKS) "  \
                    "VALUES (2, 'Jane Smith', 19, '456 Oak Ave', 85); " \
                    "INSERT INTO STUDENTS (ID,NAME,AGE,ADDRESS,MARKS)" \
                    "VALUES (3, 'Bob Johnson', 20, '789 Pine Rd', 70)";

    rc = sqlite3_exec(db, insert1, callback, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);        
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    // Query the table
    char *select = "SELECT * from STUDENTS";

    rc = sqlite3_exec(db, select, callback, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);        
    } 

    // Close the database connection
    sqlite3_close(db);

    return 0;
}