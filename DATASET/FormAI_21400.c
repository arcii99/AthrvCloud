//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define ROAD_LENGTH 40

typedef struct Car {
    int position;
    int speed;
} Car;

void printRoad(Car cars[], int numCars) {
    char road[ROAD_LENGTH+1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '-';
    }
    for (int i = 0; i < numCars; i++) {
        Car c = cars[i];
        road[c.position] = 'C';
    }
    printf("%s\n", road);
}

void simulateTrafficFlow() {
    srand(time(NULL));
    int numCars = rand() % MAX_CARS + 1;
    printf("Number of cars on the road: %d\n", numCars);
    Car cars[MAX_CARS];
    for (int i = 0; i < numCars; i++) {
        cars[i].position = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % 5;
    }
    printRoad(cars, numCars);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < numCars; j++) {
            Car c = cars[j];
            if (c.speed > 0 && rand() % 2 == 0) {
                cars[j].speed--;
            } else if (c.speed < 4 && rand() % 2 == 0) {
                cars[j].speed++;
            }
            cars[j].position += cars[j].speed;
            if (cars[j].position >= ROAD_LENGTH) {
                cars[j].position = cars[j].position - ROAD_LENGTH;
            }
        }
        printRoad(cars, numCars);
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}