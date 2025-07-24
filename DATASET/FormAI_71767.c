//FormAI DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_RECORDS 1000

// Struct to hold record information
typedef struct record {
    int id;
    char name[50];
    int age;
} Record;

// Array to hold all records
Record records[MAX_RECORDS];

// Array to hold indexed records
Record* indexedRecords[MAX_RECORDS];

// Array of pthread_t objects to hold threads
pthread_t threads[MAX_THREADS];

// Used for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to index records
void* indexRecords(void* arg) {
    int startIndex = *(int*) arg;
    int endIndex = startIndex + (MAX_RECORDS / MAX_THREADS);

    // Loop through records from given start and end indexes
    for (int i = startIndex; i < endIndex; i++) {
        indexedRecords[i] = &records[i];
    }

    // Lock mutex before printing message to ensure proper sequencing of messages
    pthread_mutex_lock(&mutex);

    printf("Thread %ld indexed records from %d to %d\n", pthread_self(), startIndex, endIndex - 1);

    // Unlock mutex before exiting thread
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    // Initialize records array
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i].id = i;
        sprintf(records[i].name, "Record %d", i);
        records[i].age = 20 + (i % 10);
    }

    // Create threads to index records
    for (int i = 0; i < MAX_THREADS; i++) {
        int* startIndex = malloc(sizeof(int));
        *startIndex = i * (MAX_RECORDS / MAX_THREADS);

        pthread_create(&threads[i], NULL, indexRecords, startIndex);
    }

    // Join threads before printing indexed records
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print all indexed records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("Record %d: %s, %d years old\n", indexedRecords[i]->id, indexedRecords[i]->name, indexedRecords[i]->age);
    }

    return 0;
}