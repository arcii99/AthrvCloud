//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define ROAD_SIZE 10

struct Car {
    int id;
    int position;
    int speed;
};

typedef struct Car Car;

int main() {
    srand(time(NULL));
    Car road[ROAD_SIZE] = {0};
    int total_cars = 0;

    // spawing initial cars randomly
    for (int i = 0; i < MAX_CARS; i++) {
        Car car = {i + 1, rand() % ROAD_SIZE, rand() % 4 + 1};
        road[car.position] = car;
        total_cars++;
        if (total_cars >= ROAD_SIZE) {
            break;
        }
    }

    // simulating traffic flow
    int loop = 1;
    while (loop) {
        // printing current state of road
        for (int p = 0; p < ROAD_SIZE; p++) {
            if (road[p].id != 0) {
                printf("%d ", road[p].id);
            } else {
                printf(". ");
            }
        }
        printf("\n");
        // moving cars
        for (int i = 0; i < ROAD_SIZE; i++) {
            if (road[i].id != 0) {
                int next_pos = i + road[i].speed;
                if (next_pos >= ROAD_SIZE) {
                    road[i] = (Car){0, 0, 0};
                    total_cars--;
                } else {
                    if (road[next_pos].id == 0) {
                        road[next_pos] = road[i];
                        road[i] = (Car){0, 0, 0};
                    }
                }
            }
        }
        // spawning new cars randomly
        int spawn = rand() % 5 + 1;
        for (int i = 0; i < spawn; i++) {
            Car car = {total_cars + 1, 0, rand() % 4 + 1};
            if (road[car.position].id == 0) {
                road[car.position] = car;
                total_cars++;
            }
        }
        // checking if all cars have passed through the road
        if (total_cars == MAX_CARS) {
            loop = 0;
        }
    }

    return 0;
}