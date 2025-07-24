//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    
    // Create the database connection
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Create the table and insert some data
    sqlite3_exec(db,
        "CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);"
        "INSERT INTO users (name, age) VALUES ('Alice', 20);"
        "INSERT INTO users (name, age) VALUES ('Bob', 30);"
        "INSERT INTO users (name, age) VALUES ('Charlie', 40);",
        NULL, NULL, NULL);
    
    // Query the database and print the results
    rc = sqlite3_prepare_v2(db,
        "SELECT name, age FROM users WHERE age > ?;",
        -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    sqlite3_bind_int(stmt, 1, 25);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* name = sqlite3_column_text(stmt, 0);
        int age = sqlite3_column_int(stmt, 1);
        printf("%s is %d years old\n", name, age);
    }
    sqlite3_finalize(stmt);
    
    // Close the database connection
    sqlite3_close(db);
    
    return 0;
}