//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 10
#define MIN_DIST 50

struct Car {
    int position;
    int speed;
    int distanceToNext;
};
typedef struct Car Car;

int main() {
    srand(time(NULL));
    int roadLength = 1000;
    int targetSpeed = 5;
    Car cars[MAX_CARS];
    int numCars = rand() % MAX_CARS + 1;
    int gap = roadLength / numCars;
    int i;
    for(i = 0; i < numCars; i++) {
        cars[i].position = i * gap;
        cars[i].distanceToNext = gap;
        cars[i].speed = targetSpeed - rand() % MAX_SPEED;
    }
    int time = 0; 
    while(time < 1000) {
        printf("Time: %d\n", time);
        for(i = 0; i < numCars; i++) {
            if(cars[i].distanceToNext > MIN_DIST) {
                int distanceMoved = cars[i].speed;
                if(cars[i].position + distanceMoved > roadLength) {
                    printf("Car %d reached the end of the road\n", i);
                    continue;
                }
                cars[i + 1].distanceToNext -= distanceMoved;
                cars[i].distanceToNext = cars[i + 1].position - cars[i].position;
                cars[i].position += distanceMoved;
            }
            printf("Car %d: position = %d, speed = %d, distance to next = %d\n", i, cars[i].position, cars[i].speed, cars[i].distanceToNext);
        }
        time++;
    }
    return 0;
}