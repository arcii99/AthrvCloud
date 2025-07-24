//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char** argv)
{
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("employees.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Create table for the employee data
    char *create_table = "CREATE TABLE IF NOT EXISTS Employees(Id INT, Name TEXT, Position TEXT);";
    rc = sqlite3_exec(db, create_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    // Insert some example data
    char *insert_data = "INSERT INTO Employees VALUES(1, 'John Smith', 'Manager');"
                        "INSERT INTO Employees VALUES(2, 'Jane Doe', 'Developer');"
                        "INSERT INTO Employees VALUES(3, 'Bob Johnson', 'Designer');";
    rc = sqlite3_exec(db, insert_data, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    // Query the database
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM Employees WHERE Position = ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    // Bind parameter for the position we want to query
    char *position = "Manager";
    sqlite3_bind_text(stmt, 1, position, strlen(position), SQLITE_STATIC);
    
    // Loop over results and print them
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        char *name = (char*)sqlite3_column_text(stmt, 1);
        char *position = (char*)sqlite3_column_text(stmt, 2);
        
        printf("ID: %d, Name: %s, Position: %s\n", id, name, position);
    }
    
    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}