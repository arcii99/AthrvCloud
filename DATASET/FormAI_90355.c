//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10000
#define MAX_SPEED 60

typedef struct {
    int id;
    int speed;
    int position;
} Car;

int main() {
    srand(time(NULL));

    Car cars[MAX_CARS];
    int num_cars = 10 + rand() % (MAX_CARS - 10 + 1);

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % (MAX_SPEED + 1);
        cars[i].position = i * 100;
    }

    while (1) {
        int max_speed = MAX_SPEED;
        for (int i = 0; i < num_cars; i++) {
            // accelerate
            if (cars[i].speed < max_speed) {
                cars[i].speed++;
            }

            // braking distance
            int dist = 0;
            for (int j = i + 1; j < num_cars; j++) {
                dist += cars[j].position - cars[j-1].position;
                if (dist > cars[i].speed) {
                    break;
                }
            }

            // decelerate
            if (dist <= cars[i].speed) {
                cars[i].speed = dist - 1;
            }

            // move car
            cars[i].position += cars[i].speed;

            // check for collisions
            for (int j = 0; j < num_cars; j++) {
                if (i != j && cars[i].position == cars[j].position) {
                    printf("Car %d collided with car %d at position %d\n", cars[i].id, cars[j].id, cars[i].position);
                    exit(1);
                }
            }

            // update max speed
            max_speed = cars[i].speed;
        }
    }

    return 0;
}