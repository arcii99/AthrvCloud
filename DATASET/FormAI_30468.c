//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Define the callback function for each row in the query result */
int callback(void *data, int argc, char **argv, char **colname) {
    int i;
    printf("%s: ", (const char*)data);
    for (i=0; i<argc; i++) {
        printf("%s = %s ; ", colname[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    const char* data = "Callback function called";

    /* Open the database */
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }

    /* Create test table */
    char* sql = "CREATE TABLE IF NOT EXISTS testtable (id integer primary key autoincrement, name TEXT, age INTEGER);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return(1);
    }

    /* Insert test data */
    sql = "INSERT INTO testtable (name, age) VALUES ('Alice', 23), ('Bob', 35), ('Charlie', 45);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return(1);
    }

    /* Query data */
    sql = "SELECT * FROM testtable WHERE age > 30;";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &err_msg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return(1);
    }

    /* Close the database */
    sqlite3_close(db);

    return(0);
}