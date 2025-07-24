//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to be executed for each record in the result set
static int callback(void *data, int argc, char **argv, char **az_col_name) {
    int i;
    printf("%s: ", (const char*)data);
    for(i=0; i<argc; i++) {
        printf("%s = %s, ", az_col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {

    // Declare variables
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Open test.db database
    rc = sqlite3_open("test.db", &db);

    if(rc) {
        // Print error message and exit program if database can't be opened
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute a simple select statement
    char *sql = "SELECT * FROM test_table WHERE column_1 > 10 AND column_2 LIKE '%hello%';";
    rc = sqlite3_exec(db, sql, callback, (void*)"Result set:", &zErrMsg);

    if(rc!=SQLITE_OK) {
        // Print error message and exit program if statement can't be executed
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}