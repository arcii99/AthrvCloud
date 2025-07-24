//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h> // include sqlite3 library for database management

int main() {
    sqlite3 *db; // declare database object
    char *err_msg = 0;
    
    int rc = sqlite3_open("example.db", &db); // open database connection
    
    if (rc != SQLITE_OK) { // check for errors
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db); // close database connection
        return 1; // exit program
    } else {
        printf("Database connection established.\n\n");
    }
    
    char *sql = "CREATE TABLE IF NOT EXISTS employees(id INT, name TEXT, age INT);"; // create new table with three columns: id, name, and age
    
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg); // execute SQL command
    
    if (rc != SQLITE_OK) { // check for errors
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg); // free memory from err_msg
    } else {
        printf("New table created: employees.\n\n");
    }
    
    sql = "INSERT INTO employees VALUES(1, 'John Doe', 30);"; // insert data into table
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    sql = "INSERT INTO employees VALUES(2, 'Jane Smith', 25);"; // insert more data into table
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    sql = "SELECT * FROM employees;"; // select all data from table
    sqlite3_stmt *res; // create statement object
    
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0); // prepare SELECT statement
    
    if (rc != SQLITE_OK) { // check for errors
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    printf("List of Employees:\n\n");
    printf("ID | Name        | Age\n");
    
    int step = sqlite3_step(res); // execute prepared statement
    
    while (step == SQLITE_ROW) {
        printf("%d  | ", sqlite3_column_int(res, 0)); // output id number
        printf("%s | ", sqlite3_column_text(res, 1)); // output name
        printf("%d\n", sqlite3_column_int(res, 2)); // output age
        step = sqlite3_step(res); // get the next row of data
    }
    
    sqlite3_finalize(res); // free memory from statement object
    sqlite3_close(db); // close database connection
    printf("\nDatabase Connection Closed.");
    
    return 0; // exit program
}