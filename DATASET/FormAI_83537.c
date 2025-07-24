//FormAI DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* callback function that prints the results of a database query */
static int print_result(void *data, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    /* open the database */
    sqlite3 *db;
    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* create table if it doesn't exist */
    char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT NOT NULL, age INTEGER NOT NULL);";
    rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* insert some data into the table */
    sql = "INSERT INTO users (name, age) VALUES ('John', 25);"
          "INSERT INTO users (name, age) VALUES ('Jane', 30);"
          "INSERT INTO users (name, age) VALUES ('Bob', 40);";
    rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* query the data from the table */
    sql = "SELECT * FROM users WHERE age > 25;";
    rc = sqlite3_exec(db, sql, print_result, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error querying data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* close the database */
    sqlite3_close(db);
    
    return 0;
}