//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 500
#define NUM_THREADS 4

sqlite3 *db;

int callback(void *data, int argc, char **argv, char **col_name) {
    int i;
    printf("%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void *queryDB(void *threadID) {
    int thread = *(int *)threadID;
    char query[MAX_QUERY_LENGTH];
    sprintf(query, "SELECT * FROM employees WHERE salary > %d", 5000 * thread);

    char *errMsg = NULL;
    int rc = sqlite3_exec(db, query, callback, (void*)query, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error with query on thread %d: %s\n", thread, errMsg);
        sqlite3_free(errMsg);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    char *errMsg = NULL;

    // Open database
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create Table and Insert Data
    char *sql = "CREATE TABLE employees(id INT PRIMARY KEY NOT NULL, name TEXT NOT NULL, salary INT NOT NULL);"
                "INSERT INTO employees (id, name, salary) VALUES (1, 'John', 10000);"
                "INSERT INTO employees (id, name, salary) VALUES (2, 'Mary', 6000);"
                "INSERT INTO employees (id, name, salary) VALUES (3, 'Bob', 2000);"
                "INSERT INTO employees (id, name, salary) VALUES (4, 'Lisa', 8000);"
                "INSERT INTO employees (id, name, salary) VALUES (5, 'David', 3000);";
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    // Create threads and query database
    pthread_t threads[NUM_THREADS];
    int threadID[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        threadID[i] = i + 1; // create unique ID for each thread
        rc = pthread_create(&threads[i], NULL, queryDB, (void *)&threadID[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i+1, rc);
            return 1;
        }
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error joining thread %d: %d\n", i+1, rc);
            return 1;
        }
    }

    // Close database
    sqlite3_close(db);
    return 0;
}