//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_cars = rand() % 101 + 50;
    int* cars = (int*) malloc(num_cars * sizeof(int));

    printf("Creating %d cars...\n", num_cars);

    for (int i = 0; i < num_cars; i++) {
        cars[i] = rand() % 81 + 20;
        printf("Car %d has a speed of %d mph.\n", i+1, cars[i]);
    }

    printf("\nSimulating traffic flow...\n");

    for (int i = 1; i < num_cars; i++) {
        int distance_between_cars = rand() % 201 + 50;
        int time_to_reach_next_car = distance_between_cars / cars[i-1];

        if (time_to_reach_next_car < 1) {
            printf("Car %d crashes into car %d!\n", i, i-1);
            break;
        }

        int new_speed = (rand() % 21 + 60) / time_to_reach_next_car;
        if (new_speed < cars[i]) {
            printf("Car %d slows down to %d mph to avoid collision!\n", i, new_speed);
            cars[i] = new_speed;
        } else {
            cars[i] = new_speed;
        }

        printf("Car %d is now traveling at %d mph.\n", i, cars[i]);
    }

    free(cars);
    return 0;
}