//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **colNames) {
    int i;
    
    for(i=0; i<argc; i++) {
        printf("%s: %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *sql;
    char *errMsg = 0;
    int rc;
    
    rc = sqlite3_open("myDatabase.db", &db);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Create table if it does not exist
    sql = "CREATE TABLE IF NOT EXISTS Employees("
          "EmployeeID INT PRIMARY KEY     NOT NULL,"
          "Name           TEXT            NOT NULL,"
          "Age            INT             NOT NULL,"
          "Salary         REAL            NOT NULL);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    // Insert data into table
    sql = "INSERT INTO Employees (EmployeeID, Name, Age, Salary) VALUES (1, 'John Doe', 30, 45000.00); "
          "INSERT INTO Employees (EmployeeID, Name, Age, Salary) VALUES (2, 'Jane Smith', 25, 35000.00); "
          "INSERT INTO Employees (EmployeeID, Name, Age, Salary) VALUES (3, 'Bob Johnson', 40, 60000.00); "
          "INSERT INTO Employees (EmployeeID, Name, Age, Salary) VALUES (4, 'Sara Lee', 27, 40000.00);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    // Query data from table
    sql = "SELECT * FROM Employees WHERE Age > 30;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    // Update data in table
    sql = "UPDATE Employees SET Salary = 55000.00 WHERE EmployeeID = 3;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    // Query updated data from table
    sql = "SELECT * FROM Employees WHERE EmployeeID = 3;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    sqlite3_close(db);
    return 0;
}