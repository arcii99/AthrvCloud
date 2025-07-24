//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CARS 10 // number of cars in the simulation
#define SIM_TIME 10 // simulation time in seconds

int trafficFlow = 0; // traffic flow counter
pthread_mutex_t flowLock; // lock for trafficFlow variable
pthread_cond_t flowCond; // condition variable for trafficFlow counter

// function that simulates a car
void *car(void *id) {
    int carId = *(int*)id;
    int startTime = rand() % 10; // random start time between 0 and 9 seconds
    sleep(startTime); // wait for start time
    printf("Car %d entered the road at time %d seconds\n", carId, startTime);
    // increment trafficFlow and signal other cars to proceed
    pthread_mutex_lock(&flowLock);
    trafficFlow++;
    pthread_cond_broadcast(&flowCond);
    pthread_mutex_unlock(&flowLock);
    // wait for traffic to clear before exiting the road
    pthread_mutex_lock(&flowLock);
    while(trafficFlow > 0) {
        pthread_cond_wait(&flowCond, &flowLock);
    }
    pthread_mutex_unlock(&flowLock);
    int endTime = rand() % 10 + startTime + 1; // random end time between startTime + 1 and startTime + 10
    printf("Car %d left the road at time %d seconds\n", carId, endTime);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // seed random number generator
    pthread_t carThreads[NUM_CARS]; // array of car threads
    int carIds[NUM_CARS]; // array of car ids
    pthread_mutex_init(&flowLock, NULL); // initialize flowLock
    pthread_cond_init(&flowCond, NULL); // initialize flowCond
    // create car threads
    for(int i = 0; i < NUM_CARS; i++) {
        carIds[i] = i + 1;
        pthread_create(&carThreads[i], NULL, car, (void*)&carIds[i]);
    }
    // wait for simulation to finish
    sleep(SIM_TIME);
    // join car threads
    for(int i = 0; i < NUM_CARS; i++) {
        pthread_join(carThreads[i], NULL);
    }
    // clean up
    pthread_mutex_destroy(&flowLock);
    pthread_cond_destroy(&flowCond);
    return 0;
}