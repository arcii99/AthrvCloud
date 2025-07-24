//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int steps = 0;  // Global variable to keep track of steps
pthread_mutex_t lock; // Declare mutex lock

// Function to simulate step counting
void* countSteps(void *arg) {
    int *totalSteps = (int*)arg;
    while(1) {
        pthread_mutex_lock(&lock);  // Acquire lock
        int randomSteps = rand() % 10 + 1; // Generate random number of steps between 1 and 10
        steps += randomSteps;
        (*totalSteps) += randomSteps;  // Update total steps taken
        printf("You took %d steps!\n", randomSteps);
        pthread_mutex_unlock(&lock);  // Release lock
        sleep(5); // Wait for 5 seconds before next step count
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    pthread_t thread; // Declare thread
    int totalSteps = 0;
    pthread_create(&thread, NULL, countSteps, &totalSteps); // Create thread

    while(1) {
        printf("Total steps taken: %d\n", totalSteps);
        printf("Current steps: %d\n", steps);
        sleep(10); // Wait for 10 seconds before next update
    }

    pthread_join(thread, NULL); // Wait for thread to exit
    pthread_mutex_destroy(&lock); // Destroy mutex lock
    return 0;
}