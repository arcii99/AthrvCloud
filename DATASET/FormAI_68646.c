//FormAI DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
// include sqlite3 library

int main(){
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    // initialize pointers needed for sqlite3 connection

    int rc = sqlite3_open("example.db", &db);
    // open or create a db named example.db

    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        // check if db was created successfully, if not, print error message
        sqlite3_close(db);
        return 1;
    }

    char *sql = "SELECT * FROM users WHERE age > ? AND gender = ?";
    // Create a query to select users where age > ? and gender = ?

    if (sqlite3_prepare_v2(db, sql, -1, &res, 0) != SQLITE_OK){
        fprintf(stderr, "Cannot prepare select query: %s\n", sqlite3_errmsg(db));
        // check if query was prepared successfully, if not, print error message
        sqlite3_close(db);
        return 1;
    }

    int age = 30;
    char *gender = "M";
    // declare age and gender variables to be used in the query

    sqlite3_bind_int(res, 1, age);
    sqlite3_bind_text(res, 2, gender, strlen(gender), 0);
    // bind the values of age and gender to the query

    int step = sqlite3_step(res);

    while (step == SQLITE_ROW){
        int id = sqlite3_column_int(res, 0);
        char *name = sqlite3_column_text(res, 1);
        int age = sqlite3_column_int(res, 2);
        char *gender = sqlite3_column_text(res, 3);
        // extract values from the result set

        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", id, name, age, gender);
        // print the values

        step = sqlite3_step(res);
    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;
}