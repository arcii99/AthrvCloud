//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define TIME_TRAVELERS 5 // number of time travelers

void *timeTraveler(void *arg); // thread routine for time travelers

int main() {
    srand(time(NULL)); // seed random number generator
    pthread_t tid[TIME_TRAVELERS]; // thread id array
    int travelerIDs[TIME_TRAVELERS]; // array to store time traveler IDs
    int i;

    printf("Welcome to the time travel simulator!\n");

    // start time traveler threads
    for (i = 0; i < TIME_TRAVELERS; i++) {
        travelerIDs[i] = i + 1;
        if (pthread_create(&tid[i], NULL, timeTraveler, &travelerIDs[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // join time traveler threads
    for (i = 0; i < TIME_TRAVELERS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    printf("All time travelers have returned to the present!\n");

    return 0;
}

void *timeTraveler(void *arg) {
    int id = *(int *)arg;
    int destination = rand() % 100; // travel to a random year
    printf("Time traveler %d is traveling to year %d\n", id, destination);
    sleep(rand() % 5 + 1); // travel time 
    printf("Time traveler %d has arrived in year %d\n", id, destination);
    return NULL;
}