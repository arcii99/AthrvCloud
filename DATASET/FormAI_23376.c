//FormAI DATASET v1.0 Category: Database querying ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
    // Establishing a connection with the database
    sqlite3 *db;
    sqlite3_open("example.db", &db);
    
    // Creating a table
    char *create_table_sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INT)";
    sqlite3_exec(db, create_table_sql, NULL, 0, NULL);
    
    // Inserting data into the table
    char *insert_sql = "INSERT INTO users (name, age) VALUES ('John Doe', 27)";
    sqlite3_exec(db, insert_sql, NULL, 0, NULL);
    
    // Querying the database
    sqlite3_stmt *statement;
    char *select_sql = "SELECT * FROM users";
    sqlite3_prepare_v2(db, select_sql, -1, &statement, NULL);
    
    // Iterating over the results of the query
    while (sqlite3_step(statement) == SQLITE_ROW) {
        int id = sqlite3_column_int(statement, 0);
        char *name = sqlite3_column_text(statement, 1);
        int age = sqlite3_column_int(statement, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }
    
    // Cleaning up
    sqlite3_finalize(statement);
    sqlite3_close(db);
    
    return 0;
}