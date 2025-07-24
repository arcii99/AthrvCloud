//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define MAX_SPEED 60
#define MIN_SPEED 20
#define MAX_CAPACITY 25
#define MIN_CAPACITY 10
#define MAX_DELAY 10
#define MIN_DELAY 5

typedef struct Road {
    int capacity;
    int current_cars;
    int speed;
    int delay;
} Road;

int main() {
    srand(time(NULL));

    Road roads[NUM_ROADS];
    for (int i = 0; i < NUM_ROADS; i++) {
        roads[i].capacity = rand() % MAX_CAPACITY + MIN_CAPACITY;
        roads[i].current_cars = 0;
        roads[i].speed = rand() % MAX_SPEED + MIN_SPEED;
        roads[i].delay = rand() % MAX_DELAY + MIN_DELAY;
    }

    int total_cars = 0;
    int time = 0;

    while (time < 60) {
        printf("Time: %d\n", time);

        for (int i = 0; i < NUM_ROADS; i++) {
            int num_cars = rand() % roads[i].capacity + 1;
            if (num_cars + roads[i].current_cars > roads[i].capacity) {
                num_cars = roads[i].capacity - roads[i].current_cars;
            }

            printf("Road %d: %d cars arrived\n", i, num_cars);
            roads[i].current_cars += num_cars;
        }

        for (int i = 0; i < NUM_ROADS; i++) {
            int delay = roads[i].delay;
            for (int j = 0; j < roads[i].current_cars; j++) {
                printf("Car %d on Road %d\n", j + 1, i);

                if (delay > 0) {
                    delay--;
                    continue;
                }

                if (j + 1 >= roads[i].speed) {
                    roads[i].current_cars--;
                    printf("Car %d exited Road %d\n", j + 1, i);
                }
            }
        }

        total_cars = 0;
        for (int i = 0; i < NUM_ROADS; i++) {
            total_cars += roads[i].current_cars;
        }

        printf("Total Cars: %d\n", total_cars);

        time++;
    }

    return 0;
}