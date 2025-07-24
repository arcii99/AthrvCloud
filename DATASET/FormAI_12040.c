//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
    // start by creating a database connection object
    sqlite3 *db;
    
    // if the database connection fails, print an error message
    if (sqlite3_open("example.db", &db)) 
    {
        printf("Failed to open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    // create the table if it doesn't exist yet
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users(id INT, name TEXT, age INT);", NULL, 0, NULL);

    // insert some example data into the table
    sqlite3_exec(db, "INSERT INTO users(id, name, age) VALUES(1, 'John Doe', 30);", NULL, 0, NULL);
    sqlite3_exec(db, "INSERT INTO users(id, name, age) VALUES(2, 'Jane Smith', 25);", NULL, 0, NULL);
    sqlite3_exec(db, "INSERT INTO users(id, name, age) VALUES(3, 'Bob Johnson', 40);", NULL, 0, NULL);

    // create a query to select all users from the table
    sqlite3_stmt *statement;
    const char* query = "SELECT * FROM users;";
    
    // prepare and execute the query
    sqlite3_prepare_v2(db, query, -1, &statement, NULL);
    int result = 0;
    
    printf("Getting all users from the database:\n");
    
    // loop through each row of results
    while (sqlite3_step(statement) == SQLITE_ROW) 
    {
        // extract the id, name, and age from the row
        int id = sqlite3_column_int(statement, 0);
        const unsigned char *name = sqlite3_column_text(statement, 1);
        int age = sqlite3_column_int(statement, 2);
        
        // print out the user's information
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
        
        // increment the result counter
        result++;
    }
    
    // if no results were found, print a message saying so
    if (result == 0)
    {
        printf("No results found!\n");
    }
    
    // clean up the database connection object and the query statement
    sqlite3_finalize(statement);
    sqlite3_close(db);
    
    return 0;
}