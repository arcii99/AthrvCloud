//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_CARS 20
#define MAX_SPEED 5
#define ROAD_LENGTH 50
#define LANE_LENGTH 10

struct car {
    int id;
    int lane;
    int distance;
    int speed;
};

void printRoad(struct car cars[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("o");
        for (int j = 0; j < LANE_LENGTH - 1; j++) {
            if (cars[i].lane == j) {
                printf("#");
            } else {
                printf("-");
            }
        }
        printf("o   ");
    }
    printf("\n");
}

void initCars(struct car cars[], int size) {
    for (int i = 0; i < size; i++) {
        cars[i].id = i;
        cars[i].distance = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].lane = rand() % LANE_LENGTH;
    }
}

void updateCars(struct car cars[], int size) {
    for (int i = 0; i < size; i++) {
        cars[i].distance += cars[i].speed;
        if (cars[i].distance >= ROAD_LENGTH) {
            cars[i].distance -= ROAD_LENGTH;
        }
    }
}

void simulateTraffic() {
    struct car cars[NUM_OF_CARS];
    srand(time(NULL));
    initCars(cars, NUM_OF_CARS);
    for (int i = 0; i < 10; i++) {
        printf("Step %d:\n", i + 1);
        printRoad(cars, NUM_OF_CARS);
        updateCars(cars, NUM_OF_CARS);
    }
}

int main() {
    simulateTraffic();
    return 0;
}