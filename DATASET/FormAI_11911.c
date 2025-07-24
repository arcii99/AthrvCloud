//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sqlite3.h>

#define NUM_THREADS 5

// Define the database name
const char* db_name = "example.db";

// Define the SQL statement
const char* sql = "SELECT * FROM customers;";

// Define the callback function
int callback(void* data, int argc, char** argv, char** column_name){
    int i;
    for(i = 0; i < argc; i++){
        printf("%s = %s\n", column_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Define thread function
void* thread_func(void* arg){
    int thread_id = *(int*) arg;
    sqlite3* db;
    char* err_msg = NULL;
    int rc = sqlite3_open(db_name, &db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    printf("Thread %d: Database opened successfully\n", thread_id);
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Error querying database: %s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }
    printf("Thread %d: Query executed successfully\n", thread_id);
    sqlite3_close(db);
    pthread_exit(NULL);
}

int main(){
    // Initialize thread variables
    int i, rc;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    // Create threads
    for(i = 0; i < NUM_THREADS; i++){
        thread_ids[i] = i + 1;
        rc = pthread_create(&threads[i], NULL, thread_func, (void*) &thread_ids[i]);
        if(rc){
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }
    // Wait for threads to complete
    for(i = 0; i < NUM_THREADS; i++){
        rc = pthread_join(threads[i], NULL);
        if(rc){
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }
    pthread_exit(NULL);
}