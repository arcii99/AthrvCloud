//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CARS 10
#define MAX_SPEED 50
#define SIM_TIME 30 // in seconds

typedef struct car {
    int id;
    int speed;
    float distance;
} car;

float road_length = 1000; // in meters
float time_unit = 1; // in seconds

car cars[NUM_CARS];

void *simulate_car(void *arg) {
    car *my_car = (car *) arg;

    while (my_car->distance < road_length) {
        my_car->distance += (my_car->speed * time_unit) / 3600; // convert km/h to m/s
        printf("Car %d has travelled %.2f meters\n", my_car->id, my_car->distance);
    }

    printf("Car %d has reached the end of the road\n", my_car->id);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % MAX_SPEED + 1; // generate a random speed between 1 and MAX_SPEED km/h
        cars[i].distance = rand() % (int) road_length; // generate a random position between 0 and road_length meters
        printf("Car %d has started with a speed of %dkm/h at %.2fm\n", cars[i].id, cars[i].speed, cars[i].distance);
    }

    printf("---Simulation started---\n");

    pthread_t threads[NUM_CARS];

    for (int i = 0; i < NUM_CARS; i++) {
        pthread_create(&threads[i], NULL, simulate_car, (void *) &cars[i]);
    }

    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("---Simulation finished---\n");

    return 0;
}