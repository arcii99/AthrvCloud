//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **columns) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", columns[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *conn;
    char *errMsg = NULL;

    int rc = sqlite3_open("example.db", &conn);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
        return 1;
    }

    char *sql = "SELECT * FROM users WHERE age > 25";

    rc = sqlite3_exec(conn, sql, callback, "Query Results", &errMsg);
    if(rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Query executed successfully\n");
    }

    sqlite3_close(conn);
    return 0;
}