//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sqlite3.h>

/* Global database connection variable */
sqlite3* db;

/* Thread function to fetch data from the database */
void* query_database(void* arg)
{
    char* query = (char*) arg;
    sqlite3_stmt* stmt;
    int rc;
    
    /* Prepare the query statement */
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing query: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }
    
    /* Execute the query statement */
    rc = sqlite3_step(stmt);
    if(rc != SQLITE_ROW && rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }
    
    /* Fetch and print the results */
    while(rc == SQLITE_ROW) {
        printf("%s = %s\n", sqlite3_column_name(stmt, 0), sqlite3_column_text(stmt, 0));
        printf("%s = %s\n", sqlite3_column_name(stmt, 1), sqlite3_column_text(stmt, 1));
        rc = sqlite3_step(stmt);
    }
    
    /* Finalize the query statement */
    sqlite3_finalize(stmt);
    
    pthread_exit(NULL);
}

/* Main function */
int main(int argc, char** argv)
{
    char* query = "SELECT name, age FROM students WHERE age > 18";
    
    /* Open the database connection */
    int rc = sqlite3_open("test.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }
    
    /* Create threads for querying the database */
    pthread_t threads[5];
    int i;
    for(i = 0; i < 5; i++) {
        rc = pthread_create(&threads[i], NULL, query_database, (void*) query);
        if(rc) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Join the threads */
    for(i = 0; i < 5; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            fprintf(stderr, "Error joining thread: %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Close the database connection */
    sqlite3_close(db);
    
    return 0;
}