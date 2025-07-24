//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLIGHTS 5
#define NUM_THREADS 7
#define MAX_BAGS 100

// Define a struct for a baggage object
typedef struct {
    int id;
    char flight[5];
    int location; // 0: Check-in, 1: Security, 2: Boarding
} Baggage;

// Global variables
Baggage bags[MAX_BAGS];
sem_t checkInSemaphore, securitySemaphore, boardingSemaphore;

// Worker functions for threads
void *checkInWorker(void *arg);
void *securityWorker(void *arg);
void *boardingWorker(void *arg);

int main() {
    int i;
    sem_init(&checkInSemaphore, 0, 1); // Only one thread allowed at Check-in
    sem_init(&securitySemaphore, 0, 0); // No Security worker allowed yet
    sem_init(&boardingSemaphore, 0, 0); // No Boarding worker allowed yet
   
    // Generate a list of bags and assign them to flights at random
    for(i = 0; i < MAX_BAGS; i++) {
        bags[i].id = i+1;
        sprintf(bags[i].flight, "FL%02d", rand()%NUM_FLIGHTS + 1);
        bags[i].location = 0; // Starting from check-in
    }
    
    // Spawn threads for check-in workers
    pthread_t checkInThreads[NUM_THREADS/2];
    printf("Spawning %d Check-in worker threads...\n", NUM_THREADS/2);
    for(i = 0; i < NUM_THREADS/2; i++) {
        pthread_create(&checkInThreads[i], NULL, checkInWorker, (void *)&i);
    }
    
    // Spawn threads for security workers
    pthread_t securityThreads[NUM_THREADS/2];
    printf("Spawning %d Security worker threads...\n", NUM_THREADS/2);
    for(i = 0; i < NUM_THREADS/2; i++) {
        pthread_create(&securityThreads[i], NULL, securityWorker, (void *)&i);
    }
    
    // Wait for threads to finish
    printf("Waiting for all threads to finish...\n");
    for(i = 0; i < NUM_THREADS/2; i++) {
        pthread_join(checkInThreads[i], NULL);
        pthread_join(securityThreads[i], NULL);
    }
    
    // Spawn threads for boarding workers
    pthread_t boardingThreads[NUM_FLIGHTS];
    printf("Spawning %d Boarding worker threads...\n", NUM_FLIGHTS);
    for(i = 0; i < NUM_FLIGHTS; i++) {
        pthread_create(&boardingThreads[i], NULL, boardingWorker, (void *)&i);
    }
    
    // Wait for threads to finish
    printf("Waiting for all threads to finish...\n");
    for(i = 0; i < NUM_FLIGHTS; i++) {
        pthread_join(boardingThreads[i], NULL);
    }
    
    printf("All threads have finished executing.\n");
    return 0;
}

// Worker function for check-in threads
void *checkInWorker(void *arg) {
    int id = *(int *)arg;
    printf("Check-in worker %d started.\n", id);
    int i;
    for(i = 0; i < MAX_BAGS; i++) {
        sem_wait(&checkInSemaphore);
        if(bags[i].location == 0) {
            // Bag is at Check-in
            printf("Check-in worker %d processed bag %d for flight %s.\n", id, bags[i].id, bags[i].flight);
            bags[i].location = 1; // Send bag to Security
            sem_post(&securitySemaphore);
        }
        sem_post(&checkInSemaphore);
    }
    printf("Check-in worker %d finished processing bags.\n", id);
    pthread_exit(NULL);
}

// Worker function for security threads
void *securityWorker(void *arg) {
    int id = *(int *)arg;
    printf("Security worker %d started.\n", id);
    int i;
    for(i = 0; i < MAX_BAGS; i++) {
        sem_wait(&securitySemaphore);
        if(bags[i].location == 1) {
            // Bag is at Security
            printf("Security worker %d processed bag %d for flight %s.\n", id, bags[i].id, bags[i].flight);
            bags[i].location = 2; // Send bag to Boarding
            sem_post(&boardingSemaphore);
        }
        sem_post(&securitySemaphore);
    }
    printf("Security worker %d finished processing bags.\n", id);
    pthread_exit(NULL);
}

// Worker function for boarding threads
void *boardingWorker(void *arg) {
    int flight = *(int *)arg;
    printf("Boarding worker for flight FL%02d started.\n", flight+1);
    int i;
    for(i = 0; i < MAX_BAGS; i++) {
        sem_wait(&boardingSemaphore);
        if(strcmp(bags[i].flight, "FL01") == 0 && bags[i].location == 2) {
            // Bag is at Boarding for flight FL01
            printf("Boarding worker for FL01 has loaded bag %d onto the plane.\n", bags[i].id);
        }
        else if(strcmp(bags[i].flight, "FL02") == 0 && bags[i].location == 2) {
            // Bag is at Boarding for flight FL02
            printf("Boarding worker for FL02 has loaded bag %d onto the plane.\n", bags[i].id);
        }
        else if(strcmp(bags[i].flight, "FL03") == 0 && bags[i].location == 2) {
            // Bag is at Boarding for flight FL03
            printf("Boarding worker for FL03 has loaded bag %d onto the plane.\n", bags[i].id);
        }
        else if(strcmp(bags[i].flight, "FL04") == 0 && bags[i].location == 2) {
            // Bag is at Boarding for flight FL04
            printf("Boarding worker for FL04 has loaded bag %d onto the plane.\n", bags[i].id);
        }
        else if(strcmp(bags[i].flight, "FL05") == 0 && bags[i].location == 2) {
            // Bag is at Boarding for flight FL05
            printf("Boarding worker for FL05 has loaded bag %d onto the plane.\n", bags[i].id);
        }
        sem_post(&boardingSemaphore);
    }
    printf("Boarding worker for flight FL%02d finished loading all bags onto the plane.\n", flight+1);
    pthread_exit(NULL);
}