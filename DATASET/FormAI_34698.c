//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function to handle an error. It is called whenever a an issue arises in the SQLite API
static int handle_error(void *data, const char *errmsg) 
{
    fprintf(stderr, "Error: %s\n", errmsg);
    return 0;
}

int main() 
{
    sqlite3 *db;
    char *zerrmsg = 0;
    int status;

    // Open/create a database
    status = sqlite3_open("test.db", &db);

    if(status != SQLITE_OK) {
        printf("Failed to open/create the database. Error: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table 
    const char *create_table_query = "CREATE TABLE IF NOT EXISTS users ("
                                     "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                     "name TEXT NOT NULL, "
                                     "age INTEGER);";

    // Execute the query
    status = sqlite3_exec(db, create_table_query, 0, 0, &zerrmsg);

    if(status != SQLITE_OK) {
      printf("Failed to create the table. Error: %s", zerrmsg);
      sqlite3_free(zerrmsg);
      sqlite3_close(db);
      return 1;
    }

    // Insert some sample data into the table
    const char *insert_query_1 = "INSERT INTO users (name, age) VALUES ('John', 25);";
    const char *insert_query_2 = "INSERT INTO users (name, age) VALUES ('Jane', 30);";

    // Execute the queries
    status = sqlite3_exec(db, insert_query_1, 0, 0, &zerrmsg);
    if(status != SQLITE_OK) {
      printf("Failed to insert data into the table. Error: %s", zerrmsg);
      sqlite3_free(zerrmsg);
      sqlite3_close(db);
      return 1;
    }

    status = sqlite3_exec(db, insert_query_2, 0, 0, &zerrmsg);
    if(status != SQLITE_OK) {
      printf("Failed to insert data into the table. Error: %s", zerrmsg);
      sqlite3_free(zerrmsg);
      sqlite3_close(db);
      return 1;
    }

   // Query the data in the table
    const char *select_query = "SELECT * FROM users";

    // Execute the query
    sqlite3_stmt *statement;
    status = sqlite3_prepare_v2(db, select_query, -1, &statement, 0);
    if(status != SQLITE_OK) {
      printf("Failed to query the data in the table. Error: %s", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
    }

   // Parse the data in the table and print it to the console
    while (sqlite3_step(statement) == SQLITE_ROW) {
        int id = sqlite3_column_int(statement, 0);
        const char *name = (char*)sqlite3_column_text(statement, 1);
        int age = sqlite3_column_int(statement, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    // Free up the statement and  close the database
    sqlite3_finalize(statement);
    sqlite3_close(db);

    return 0;
}