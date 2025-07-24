//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sqlite3.h>

#define DB_NAME "test_db.db"
#define MAX_QUERY_LENGTH 200

sqlite3 *db;

void* queryDB(void* arg) {
    char *query = (char*) arg;
    sqlite3_stmt *statement;
    int result;

    // Prepare the statement for execution
    result = sqlite3_prepare_v2(db, query, -1, &statement, NULL);
    if (result != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    // Execute the statement, and print the results
    printf("Running query: %s\n", query);
    while (sqlite3_step(statement) == SQLITE_ROW) {
        printf("Result: %s\n", sqlite3_column_text(statement, 0));
    }

    // Clean up the statement
    sqlite3_finalize(statement);

    return NULL;
}

int main() {
    // Initialize the database
    int result = sqlite3_open(DB_NAME, &db);
    if (result != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Set up the queries to run
    char query1[MAX_QUERY_LENGTH] = "SELECT name FROM customers;";
    char query2[MAX_QUERY_LENGTH] = "SELECT COUNT(*) FROM orders;";

    // Run the queries in separate threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, queryDB, (void*) query1);
    pthread_create(&thread2, NULL, queryDB, (void*) query2);

    // Wait for the threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Clean up the database
    sqlite3_close(db);

    return 0;
}