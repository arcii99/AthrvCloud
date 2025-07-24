//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 5
#define MAX_TRAVEL_TIME 50

typedef struct car {
    int speed;
    int travel_time;
    int distance;
} Car;

void print_traffic(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d -- Speed: %d, Travel Time: %d, Distance: %d\n", i+1, cars[i].speed, cars[i].travel_time, cars[i].distance);
    }
}

void update_traffic(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].travel_time > 0) { // car is still on road
            if (cars[i].distance + cars[i].speed > MAX_TRAVEL_TIME) { // car is about to leave road
                cars[i].distance = MAX_TRAVEL_TIME;
                cars[i].travel_time = 0;
                cars[i].speed = 0;
            } else {
                cars[i].distance += cars[i].speed; // car moves forward
            }
        }
    }
}

void initialize_traffic(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].speed = (rand() % MAX_SPEED) + 1; // set random speed between 1 and MAX_SPEED
        cars[i].travel_time = (rand() % MAX_TRAVEL_TIME) + 1; // set random travel time between 1 and MAX_TRAVEL_TIME
        cars[i].distance = 0;
    }
}

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];
    initialize_traffic(cars);
    int time = 1;
    while (1) { // simulation loop
        printf("Time %d\n", time);
        print_traffic(cars);
        update_traffic(cars);
        if (time == MAX_TRAVEL_TIME) { // simulation is over
            break;
        }
        printf("\n");
        time++;
    }
    return 0;
}