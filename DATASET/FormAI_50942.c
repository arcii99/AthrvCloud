//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_TIME 60
#define ROAD_LENGTH 100

int cars_on_road = 0; // shared variable
pthread_mutex_t mutex; // mutex for synchronizing access to cars_on_road

void* car(void* arg) {
    int id = *(int*) arg; // id is the thread number
    int distance = 0; // the car's current position on the road
    int speed = rand() % 5 + 1; // the car's speed

    while (distance < ROAD_LENGTH) {
        pthread_mutex_lock(&mutex); // lock the mutex to access shared variable
        if (cars_on_road < MAX_CARS) { // if there is room for the car on the road
            cars_on_road++; // increment the number of cars on the road
            printf("Car %d enters the road\n", id);
            pthread_mutex_unlock(&mutex); // unlock the mutex
            distance += speed; // move the car forward
        } else {
            printf("Car %d has to wait\n", id);
            pthread_mutex_unlock(&mutex); // unlock the mutex
            usleep(50000); // sleep for 50ms to simulate waiting
        }
    }

    pthread_mutex_lock(&mutex); // lock the mutex to access shared variable
    cars_on_road--; // decrement the number of cars on the road
    printf("Car %d exits the road\n", id);
    pthread_mutex_unlock(&mutex); // unlock the mutex
    pthread_exit(NULL); // exit the thread
}

int main() {
    srand(time(NULL)); // seed the random number generator
    pthread_t cars[MAX_CARS];
    int ids[MAX_CARS];
    pthread_mutex_init(&mutex, NULL); // initialize the mutex

    for (int i = 0; i < MAX_CARS; i++) {
        ids[i] = i;
        pthread_create(&cars[i], NULL, car, &ids[i]); // create the threads
        usleep(50000); // sleep for 50ms to stagger thread creation
    }

    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(cars[i], NULL); // wait for the threads to finish
    }

    pthread_mutex_destroy(&mutex); // destroy the mutex
    return 0;
}