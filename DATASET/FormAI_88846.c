//FormAI DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// callback function to print the result of SELECT queries
static int callback(void *data, int argc, char **argv, char **colNames)
{
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// function to run the SELECT query
void runQuery(sqlite3 *db, char *query)
{
    char *errorMsg;
    int rc;

    rc = sqlite3_exec(db, query, callback, 0, &errorMsg);
    if (rc != SQLITE_OK) {
        printf("Error running query: %s\n", errorMsg);
        sqlite3_free(errorMsg);
    }
}

int main(int argc, char **argv)
{
    sqlite3 *db;
    char *errorMsg;
    int rc;

    // open the database
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        printf("Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // create a table and insert some data
    char *createTable = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    char *insertData = "INSERT INTO users (name, age) VALUES ('John', 30);"
                       "INSERT INTO users (name, age) VALUES ('Jane', 25);"
                       "INSERT INTO users (name, age) VALUES ('Bob', 50);";
    rc = sqlite3_exec(db, createTable, 0, 0, &errorMsg);
    if (rc != SQLITE_OK) {
        printf("Error creating table: %s\n", errorMsg);
        sqlite3_free(errorMsg);
    }
    rc = sqlite3_exec(db, insertData, 0, 0, &errorMsg);
    if (rc != SQLITE_OK) {
        printf("Error inserting data: %s\n", errorMsg);
        sqlite3_free(errorMsg);
    }

    // run some SELECT queries
    printf("Querying users aged 25:\n");
    runQuery(db, "SELECT * FROM users WHERE age = 25;");
    printf("Querying users named 'John':\n");
    runQuery(db, "SELECT * FROM users WHERE name = 'John';");

    // close the database
    sqlite3_close(db);
    return 0;
}