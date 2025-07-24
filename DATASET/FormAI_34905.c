//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60
#define MIN_SPEED 30
#define MAX_ACCEL 5
#define MIN_ACCEL 1
#define MAX_CARS 20
#define MAX_ROAD_DIST 1000
#define MAX_SIM_TIME 120

struct car {
    int speed;
    int position; 
};

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printRoad(int roadLength, struct car* cars, int numCars) {
    char road[roadLength + 1];
    for (int i = 0; i < roadLength; i++) {
        road[i] = '-';
    }
    for (int i = 0; i < numCars; i++) {
        int pos = cars[i].position;
        road[pos] = 'c';
    }
    road[roadLength] = '\0';
    printf("%s\n", road);
}

void updateCarPositions(struct car* cars, int numCars) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].speed > 0) {
            cars[i].position += cars[i].speed;
        }
    }
}

void updateCarSpeeds(struct car* cars, int numCars) {
    for (int i = 0; i < numCars; i++) {
        int accel = getRandomInt(MIN_ACCEL, MAX_ACCEL);
        int distToNextCar = MAX_ROAD_DIST; 
        for (int j = i + 1; j < numCars; j++) {
            int distBetween = cars[j].position - cars[i].position;
            if (distBetween < distToNextCar) {
                distToNextCar = distBetween;
            }
        }
        if (distToNextCar < MAX_SPEED) {
            cars[i].speed -= accel;
        } else if (cars[i].speed < MAX_SPEED) {
            cars[i].speed += accel;
        }
        if (cars[i].speed > distToNextCar) {
            cars[i].speed = distToNextCar;
        }
    }
}

int main() {
    srand(time(NULL));
    int roadLength = MAX_ROAD_DIST;
    int numCars = getRandomInt(1, MAX_CARS);
    struct car cars[numCars];
    for (int i = 0; i < numCars; i++) {
        cars[i].speed = getRandomInt(MIN_SPEED, MAX_SPEED);
        cars[i].position = getRandomInt(0, roadLength);
    }
    int simTime = getRandomInt(1, MAX_SIM_TIME);
    printf("Traffic Simulation for %d seconds\n\n", simTime);
    for (int i = 0; i < simTime; i++) {
        printf("Second %d:\n", i);
        printRoad(roadLength, cars, numCars);
        updateCarSpeeds(cars, numCars);
        updateCarPositions(cars, numCars);
        printf("\n");
    }

    return 0;
}