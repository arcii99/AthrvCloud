//FormAI DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the columns of the table
#define COL_NUM 4
#define COL_ID 0
#define COL_NAME 1
#define COL_AGE 2
#define COL_SALARY 3

// Callback function to display the query result
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    printf("\n");
    for(i=0; i<argc; i++) {
        printf("%s: %s\n",azColName[i],argv[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {

    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // Open the database
    rc = sqlite3_open("employee.db", &db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Run the SELECT query
    printf("Querying all employees...\n");
    char *sql = "SELECT * FROM employees;";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Print the results
    printf("Done.\n");

    // Close the database
    sqlite3_close(db);

    return 0;
}