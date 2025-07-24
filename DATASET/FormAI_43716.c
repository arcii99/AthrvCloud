//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 30
#define MAX_CARS 8

typedef struct {
    int position;
    int speed;
} Car;

void initialize_cars(Car * cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = LANE_LENGTH - (i + 1) * (LANE_LENGTH / MAX_CARS + 1);
        cars[i].speed = rand() % 6 + 1;
    }
}

void display_lane(Car * cars) {
    char lane[LANE_LENGTH];
    for (int i = 0; i < LANE_LENGTH; i++) {
        lane[i] = '-';
    }
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].position >= 0 && cars[i].position < LANE_LENGTH) {
            lane[cars[i].position] = 'C';
        }
    }
    for (int i = 0; i < LANE_LENGTH; i++) {
        printf("%c", lane[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];
    initialize_cars(cars);
    int current_tick = 0;
    while (1) {
        printf("Tick %d:\n", current_tick);
        display_lane(cars);
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].position >= 0 && cars[i].position < LANE_LENGTH) {
                int distance_to_next_car;
                if (i == MAX_CARS - 1) {
                    distance_to_next_car = LANE_LENGTH - cars[i].position;
                } else {
                    distance_to_next_car = cars[i + 1].position - cars[i].position - 1;
                }
                if (cars[i].speed < distance_to_next_car) {
                    cars[i].position += cars[i].speed;
                } else {
                    cars[i].position = cars[i + 1].position - 1;
                }
            } else {
                cars[i].position = -1;
            }
        }
        int empty_spots = 0;
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].position < 0) {
                empty_spots++;
            }
        }
        if (empty_spots > 0) {
            if (rand() % 2 == 1) {
                for (int i = 0; i < MAX_CARS; i++) {
                    if (cars[i].position < 0) {
                        cars[i].position = 0;
                        cars[i].speed = rand() % 6 + 1;
                        empty_spots--;
                        if (empty_spots == 0) {
                            break;
                        }
                    }
                }
            }
        }
        current_tick++;
        printf("\n");
    }
    return 0;
}