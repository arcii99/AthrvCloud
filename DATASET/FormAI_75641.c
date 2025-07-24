//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROAD_LENGTH 1000
#define MAX_CARS 1000
#define MAX_SPEED 80
#define MIN_SPEED 20
#define MAX_TIME_PERIOD 30
#define MIN_TIME_PERIOD 5
#define MAX_WAIT_TIME 5
#define MIN_WAIT_TIME 1
#define MAX_STOP_DISTANCE 10
#define MIN_STOP_DISTANCE 2

struct Car {
    int x, y;
    int speed;
    int time_period;
    int wait_time;
    int stop_distance;
    int stopped;
};

/*
Function to generate a random car for simulation
*/
struct Car generate_random_car(int pos) {
    struct Car car;
    car.x = pos;
    car.y = 0;
    car.speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    car.time_period = (rand() % (MAX_TIME_PERIOD - MIN_TIME_PERIOD + 1)) + MIN_TIME_PERIOD;
    car.wait_time = (rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME + 1)) + MIN_WAIT_TIME;
    car.stop_distance = (rand() % (MAX_STOP_DISTANCE - MIN_STOP_DISTANCE + 1)) + MIN_STOP_DISTANCE;
    car.stopped = 0;
    return car;
}

int main() {
    srand(time(NULL));
    int road[MAX_ROAD_LENGTH] = {0};
    struct Car cars[MAX_CARS];
    int num_cars = 0;
    int timer = 0;

    // Adding cars to the road
    while (1) {
        for (int i = num_cars; i < MAX_CARS; i++) {
            cars[i] = generate_random_car(0);
            num_cars++;
            if (rand() % 2 == 0) {
                break;
            }
        }
        if (num_cars >= MAX_CARS) {
            break;
        }
    }

    // Simulation loop
    while (1) {
        // Move cars
        for (int i = 0; i < num_cars; i++) {
            struct Car *car = &cars[i];
            if (car->stopped) {
                if (timer - car->wait_time >= car->time_period) {
                    car->stopped = 0;
                    car->wait_time = 0;
                }
            } else {
                car->y += car->speed;
                if (car->y >= road[car->x] - car->stop_distance) {
                    car->stopped = 1;
                    car->wait_time = timer;
                }
            }
        }

        // Update road state
        for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
            int cars_on_cell = 0;
            for (int j = 0; j < num_cars; j++) {
                if (cars[j].x == i && cars[j].y >= 0 && cars[j].y < MAX_ROAD_LENGTH) {
                    cars_on_cell++;
                }
            }
            road[i] = cars_on_cell;
        }

        // Display road state
        system("cls");
        printf("\n\n");
        for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
            for (int j = 0; j < road[i]; j++) {
                printf("|");
            }
            for (int j = road[i]; j < MAX_ROAD_LENGTH; j++) {
                printf(" ");
            }
        }
        printf("\n\n");

        // Wait
        for (int i = 0; i < 10000000; i++) {
        }

        // Increment timer
        timer++;
    }
    return 0;
}