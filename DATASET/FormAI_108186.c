//FormAI DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// The callback function to execute for each row selected from the database
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    printf("\n");
    for(i = 0; i < argc; i++){
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main(){
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("example.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    char *sql = "CREATE TABLE IF NOT EXISTS users ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "name TEXT NOT NULL, "
                "age INTEGER NOT NULL"
                ");";
    rc = sqlite3_exec(db, sql, NULL, 0, NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Insert some data
    sql = "INSERT INTO users (name, age) VALUES ('John', 25), ('Jane', 30), ('Bob', 40);";
    rc = sqlite3_exec(db, sql, NULL, 0, NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Select data from the table
    sql = "SELECT * FROM users;";
    rc = sqlite3_exec(db, sql, callback, NULL, NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}