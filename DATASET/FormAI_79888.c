//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 //maximum number of cars on road
#define SPEED_LIMIT 60 //speed limit in km/h
#define TRAFFIC_LIGHT_DISTANCE 1000 //distance between traffic lights in meters

typedef struct Car {
    int speed;
    int position;
} Car;

int main() {
    srand(time(0)); //initialize random number generator with current time

    int time = 0; //initialize simulation time to 0 seconds
    int distance_traveled = 0; //initialize total distance traveled by all cars to 0

    Car cars[MAX]; //initialize array of cars on road
    for (int i = 0; i < MAX; i++) {
        cars[i].speed = rand() % SPEED_LIMIT + 1; //randomly assign speed to each car between 1 to SPEED_LIMIT
        cars[i].position = i * 50; //assign initial position to each car, spaced 50 meters apart
    }

    while (distance_traveled < MAX * TRAFFIC_LIGHT_DISTANCE) { //while all cars have not passed all traffic lights
        for (int i = 0; i < MAX; i++) {
            int distance_to_traffic_light = ((cars[i].position / TRAFFIC_LIGHT_DISTANCE) + 1) * TRAFFIC_LIGHT_DISTANCE - cars[i].position; //calculate distance to next traffic light
            if (distance_to_traffic_light < cars[i].speed * 10) { //if car will reach traffic light in next 10 seconds
                cars[i].speed = distance_to_traffic_light / 10; //slow down car to avoid red light
            }
            else {
                cars[i].speed = rand() % SPEED_LIMIT + 1; //randomly assign speed to each car between 1 to SPEED_LIMIT
            }
            cars[i].position += cars[i].speed / 10; //calculate new position of car after 1 second
            distance_traveled += cars[i].speed / 10; //add distance traveled by this car in last 1 second to total distance traveled
        }
        time++; //increment simulation time by 1 second
    }
    printf("All cars have passed all traffic lights in %d seconds.\n", time);

    return 0;
}