//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100
#define MAX_SPEED 5

int cars[MAX_CARS];
int speeds[MAX_CARS];

void print_road() {
    int i, j;
    for (i = 0; i < ROAD_LENGTH; i++) {
        int car = -1;
        for (j = 0; j < MAX_CARS; j++) {
            if (cars[j] == i) {
                car = j;
                break;
            }
        }
        if (car == -1) {
            printf("-");
        } else {
            printf("%d", car);
        }
    }
    printf("\n");
}

void accelerate() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        if (speeds[i] < MAX_SPEED) {
            speeds[i]++;
        }
    }
}

void decelerate() {
    int i, j;
    for (i = 0; i < MAX_CARS; i++) {
        for (j = i + 1; j < MAX_CARS; j++) {
            if (cars[j] > cars[i]) {
                break;
            }
            if (cars[j] == cars[i] + 1) {
                if (speeds[i] > cars[j] - cars[i]) {
                    speeds[i] = cars[j] - cars[i];
                }
                break;
            }
        }
    }
}

void move_cars() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        cars[i] += speeds[i];
        if (cars[i] >= ROAD_LENGTH) {
            cars[i] = -1;
            speeds[i] = 0;
        }
    }
}

void add_car() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        if (cars[i] == -1) {
            cars[i] = 0;
            speeds[i] = rand() % MAX_SPEED + 1;
            break;
        }
    }
}

int main() {
    int tick, i;
    srand(time(NULL));
    for (i = 0; i < MAX_CARS; i++) {
        cars[i] = -1;
        speeds[i] = 0;
    }
    tick = 0;
    while (tick < 100) {
        if (rand() % 100 < 20) {
            add_car();
        }
        decelerate();
        accelerate();
        move_cars();
        print_road();
        tick++;
    }
    return 0;
}