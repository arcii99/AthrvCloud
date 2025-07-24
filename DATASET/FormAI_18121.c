//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sqlite3.h>

// The database used for this example
#define DB_NAME "example.db"

// Struct for passing argument to thread function
struct ThreadArg {
    int id;
    char* query;
};

void* query_database(void* arg) {
    struct ThreadArg* thread_arg = (struct ThreadArg*)arg;
    int thread_id = thread_arg->id;
    char* query = thread_arg->query;

    sqlite3* db;
    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Thread %d: Error opening database: %s\n", thread_id, sqlite3_errmsg(db));
        sqlite3_close(db);
        pthread_exit(NULL);
    }

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Thread %d: Error preparing statement: %s\n", thread_id, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        pthread_exit(NULL);
    }

    int row_count = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        row_count++;
        // The actual data retrieval code will depend on the specific database schema used
    }

    printf("Thread %d: Query returned %d rows.\n", thread_id, row_count);

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    pthread_exit(NULL);
}

int main() {
    // Initialize thread arguments and queries
    char* query1 = "SELECT * FROM users";
    struct ThreadArg arg1 = {1, query1};
    char* query2 = "SELECT SUM(amount) FROM transactions WHERE type='debit'";
    struct ThreadArg arg2 = {2, query2};

    // Initialize and launch threads
    pthread_t threads[2];
    int rc1 = pthread_create(&threads[0], NULL, query_database, &arg1);
    int rc2 = pthread_create(&threads[1], NULL, query_database, &arg2);

    // Check if threads were successfully created
    if (rc1 || rc2) {
        fprintf(stderr, "Error: Unable to create threads.\n");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Program finished.\n");

    return EXIT_SUCCESS;
}