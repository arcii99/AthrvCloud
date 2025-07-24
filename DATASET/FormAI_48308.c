//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define ROAD_LENGTH 20
#define CAR_DENSITY 0.3
#define MAX_SPEED 5
#define MIN_GAP 2

typedef struct {
    int position;
    int speed;
    int accel;
    int gap;
} Car;

void initialize(Car cars[ROAD_LENGTH][NUM_ROADS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROADS; i++) {
        for (int j = 0; j < ROAD_LENGTH; j++) {
            if ((double)rand() / RAND_MAX < CAR_DENSITY) {
                cars[j][i].position = j;
                cars[j][i].speed = rand() % MAX_SPEED;
                cars[j][i].accel = 0;
                cars[j][i].gap = MIN_GAP + rand() % MAX_SPEED;
            }
        }
    }
}

void update(Car cars[ROAD_LENGTH][NUM_ROADS]) {
    for (int i = 0; i < NUM_ROADS; i++) {
        for (int j = 0; j < ROAD_LENGTH; j++) {
            if (cars[j][i].position != -1) {
                int next_position = (j + cars[j][i].speed) % ROAD_LENGTH;
                if (next_position != cars[j][i].position) {
                    int next_gap = cars[next_position][i].position - cars[j][i].position - 1;
                    if (next_gap < cars[j][i].gap) {
                        cars[j][i].accel = 0;
                    } else {
                        cars[j][i].accel = (next_gap - cars[j][i].gap) / (cars[j][i].gap * cars[j][i].gap);
                        if (cars[j][i].accel > MAX_SPEED) {
                            cars[j][i].accel = MAX_SPEED;
                        }
                    }
                    cars[j][i].speed += cars[j][i].accel;
                    if (cars[j][i].speed > MAX_SPEED) {
                        cars[j][i].speed = MAX_SPEED;
                    }
                    cars[next_position][i] = cars[j][i];
                    cars[j][i].position = -1;
                }
            }
        }
    }
}

void print(Car cars[ROAD_LENGTH][NUM_ROADS]) {
    for (int i = 0; i < NUM_ROADS; i++) {
        printf("Road %d: ", i + 1);
        for (int j = 0; j < ROAD_LENGTH; j++) {
            if (cars[j][i].position != -1) {
                printf("%c", 'A' + i);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    Car cars[ROAD_LENGTH][NUM_ROADS];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        for (int j = 0; j < NUM_ROADS; j++) {
            cars[i][j].position = -1;
        }
    }
    initialize(cars);
    print(cars);
    for (int i = 0; i < 10; i++) {
        update(cars);
        print(cars);
    }
    return 0;
}