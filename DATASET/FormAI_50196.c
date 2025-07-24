//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void* timeTravelerFunction(void* arg);

int main() {
    srand(time(NULL));
    pthread_t timeTraveler1, timeTraveler2, timeTraveler3;
    int return_val1, return_val2, return_val3;

    return_val1 = pthread_create(&timeTraveler1, NULL, timeTravelerFunction, NULL);
    if (return_val1 != 0) {
        fprintf(stderr, "Error: Unable to create thread 1.\n");
        exit(EXIT_FAILURE);
    }

    return_val2 = pthread_create(&timeTraveler2, NULL, timeTravelerFunction, NULL);
    if (return_val2 != 0) {
        fprintf(stderr, "Error: Unable to create thread 2.\n");
        exit(EXIT_FAILURE);
    }

    return_val3 = pthread_create(&timeTraveler3, NULL, timeTravelerFunction, NULL);
    if (return_val3 != 0) {
        fprintf(stderr, "Error: Unable to create thread 3.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(timeTraveler1, NULL);
    pthread_join(timeTraveler2, NULL);
    pthread_join(timeTraveler3, NULL);

    printf("All time travelers have returned.\n");

    return 0;
}

void* timeTravelerFunction(void* arg) {
    const int MAX_YEARS_TRAVELED = 1000;
    const int WAIT_TIME_MIN = 1;
    const int WAIT_TIME_MAX = 5;
    int yearsTraveled = rand() % MAX_YEARS_TRAVELED;
    int waitTime = (rand() % WAIT_TIME_MAX) + WAIT_TIME_MIN;

    printf("Time traveler has traveled %d years in %d seconds.\n", yearsTraveled, waitTime);
    sleep(waitTime);
    printf("Time traveler has returned to present day.\n");

    pthread_exit(NULL);
}