//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// a callback function to handle each row of data returned from the query
static int callback(void *data, int argc, char **argv, char **colNames) {
    int i;
    printf("--------------------\n");
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main() {
    // initialize the database connection
    sqlite3 *db;
    int status = sqlite3_open("example.db", &db);
    if(status != SQLITE_OK) {
        printf("Error opening database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
  
    // create a table
    char *sqlCreateTable = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER, city TEXT)";
    status = sqlite3_exec(db, sqlCreateTable, NULL, NULL, NULL);
    if(status != SQLITE_OK) {
        printf("Error creating table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // insert some data
    char *sqlInsert = "INSERT INTO users (name, age, city) VALUES ('John Doe', 25, 'New York')";
    status = sqlite3_exec(db, sqlInsert, NULL, NULL, NULL);
    if(status != SQLITE_OK) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlInsert = "INSERT INTO users (name, age, city) VALUES ('Jane Doe', 30, 'Los Angeles')";
    status = sqlite3_exec(db, sqlInsert, NULL, NULL, NULL);
    if(status != SQLITE_OK) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlInsert = "INSERT INTO users (name, age, city) VALUES ('Bob Smith', 20, 'Chicago')";
    status = sqlite3_exec(db, sqlInsert, NULL, NULL, NULL);
    if(status != SQLITE_OK) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // query the data
    char *sqlSelect = "SELECT * FROM users WHERE age > 25 AND city = 'Los Angeles'";
    status = sqlite3_exec(db, sqlSelect, callback, NULL, NULL);
    if(status != SQLITE_OK) {
        printf("Error selecting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // close the database connection
    sqlite3_close(db);
    return 0;
}