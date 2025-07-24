//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// callback function to handle the results of our query
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    printf("I found a %s %s! Yay!\n", argv[0], argv[1]);
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc; // return code
    
    // open the database
    rc = sqlite3_open("fruits.db", &db);
    if(rc) {
        printf("Oh no! Could not open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    printf("Hello there! Let's find some colorful fruits!\n");
    
    // execute a query to find all fruits with more than one color
    rc = sqlite3_exec(db, "SELECT name, colors FROM fruits WHERE colors > 1", callback, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        printf("Aww, I couldn't find any colorful fruits: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    
    // close the database
    sqlite3_close(db);
    printf("Yay, we found some colorful fruits! That's awesome!\n");
    return 0;
}