//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_SIZE 100 // Maximum size of the database
#define MAX_THREADS 10 // Maximum number of threads that can access the database

int database[MAX_SIZE]; // The database array
int index = 0; // Current index in the database
sem_t semaphore; // Semaphore to control access to the database

void *add_entry(void *arg) {
    int entry = rand() % 100; // Generate a random entry between 0 and 99
    sem_wait(&semaphore); // Wait for the semaphore to become available
    if (index < MAX_SIZE) {
        database[index] = entry; // Add the entry to the database
        index++; // Increment the index
        printf("Added entry %d\n", entry);
    } else {
        printf("Database is full, cannot add entry\n");
    }
    sem_post(&semaphore); // Release the semaphore
    pthread_exit(NULL); // Exit the thread
}

void *remove_entry(void *arg) {
    sem_wait(&semaphore); // Wait for the semaphore to become available
    if (index > 0) {
        int entry = database[index-1]; // Get the last entry in the database
        index--; // Decrement the index
        printf("Removed entry %d\n", entry);
    } else {
        printf("Database is empty, cannot remove entry\n");
    }
    sem_post(&semaphore); // Release the semaphore
    pthread_exit(NULL); // Exit the thread
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    pthread_t threads[MAX_THREADS]; // Array of thread IDs
    sem_init(&semaphore, 0, 1); // Initialize the semaphore to 1 (unlocked)
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, add_entry, NULL); // Create a thread to add an entry
        } else {
            pthread_create(&threads[i], NULL, remove_entry, NULL); // Create a thread to remove an entry
        }
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }
    sem_destroy(&semaphore); // Destroy the semaphore
    return 0;
}