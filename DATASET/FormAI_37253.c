//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* This function gets called once for every row that is returned from the database */
int cb(void *data, int argc, char **argv, char **columns){
    int i;
    for(i=0; i<argc; i++){
        printf("%s: %s\n", columns[i], argv[i]);
    }
    printf("----------------------------------\n");
    return 0;
}

/* The main function */
int main(){
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;
    char *err_msg = 0;
    char *sql;
    const char* data = "Callback function called";

    /* Open the database */
    rc = sqlite3_open("example.db", &db);

    /* Create the table */
    sql = "CREATE TABLE IF NOT EXISTS example_table (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, city TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    /* Insert some data */
    sql = "INSERT INTO example_table (name, age, city) VALUES ('John Doe', 30, 'New York'), ('Jane Doe', 25, 'Los Angeles'), ('Bob Smith', 40, 'Chicago');";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    /* Query the database */
    sql = "SELECT * FROM example_table WHERE age > 28;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    /* Execute the query */
    if(rc == SQLITE_OK){
        sqlite3_step(stmt);
    }

    /* Print the results */
    printf("Query results:\n");
    rc = sqlite3_exec(db, sql, cb, (void*)data, &err_msg);

    /* Close the database */
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}