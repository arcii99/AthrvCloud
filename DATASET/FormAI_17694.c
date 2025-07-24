//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef struct {
    sqlite3 *conn;
    bool running;
} AsyncQuery;

void query_callback(void *data, int argc, char**argv, char **cols) {
    int i;
    printf("Number of columns returned: %d\n", argc);
    for(i=0; i<argc; i++) {
        printf("%s: %s\n", cols[i], argv[i] ? argv[i] : "NULL");
    }
}

void async_query(AsyncQuery *a_query, const char* query, void (*callback)(void*, int, char**, char**), void *data) {
    sqlite3_exec(a_query->conn, query, callback, data, NULL);
}

int main() {
    AsyncQuery a_query = {
        .conn = NULL,
        .running = true
    };

    if(sqlite3_open("test.db", &a_query.conn) != SQLITE_OK) {
        perror("Error opening database");
        exit(EXIT_FAILURE);
    }

    async_query(&a_query, "CREATE TABLE IF NOT EXISTS People (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);", NULL, NULL);
    async_query(&a_query, "INSERT INTO People (id, name, age) VALUES (1, 'John', 25);", NULL, NULL);
    async_query(&a_query, "SELECT * FROM People;", query_callback, NULL);

    while(a_query.running) {
        sqlite3_exec(a_query.conn, "SELECT DISTINCT changes() FROM People;", query_callback, NULL, NULL);
        sleep(1);
    }

    if(sqlite3_close(a_query.conn) != SQLITE_OK) {
        fprintf(stderr, "Could not close database: %s\n", sqlite3_errmsg(a_query.conn));
        exit(EXIT_FAILURE);
    }

    return 0;
}