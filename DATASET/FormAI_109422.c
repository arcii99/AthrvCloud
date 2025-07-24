//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000

typedef struct Car {
    int speed;
    int position;
} Car;

void init_traffic_flow(Car cars[], int num_cars);
void print_cars(Car cars[], int num_cars);
void update_cars(Car cars[], int num_cars);
int check_collision(Car car1, Car car2);

int main() {
    Car cars[MAX_CARS];
    int num_cars = 10;
    int tick = 0;

    // Seed random number generator
    srand(time(NULL));

    // Initialize traffic flow
    init_traffic_flow(cars, num_cars);

    // Simulate traffic flow for 100 ticks
    while (tick < 100) {
        // Print car positions
        printf("Tick %d:\n", tick);
        print_cars(cars, num_cars);

        // Update car positions
        update_cars(cars, num_cars);
        tick++;

        // Check for collisions
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (check_collision(cars[i], cars[j])) {
                    printf("Collision between car %d and car %d!\n", i, j);
                    exit(1);
                }
            }
        }

        // Wait for half a second
        usleep(500000);
    }

    return 0;
}

void init_traffic_flow(Car cars[], int num_cars) {
    // Initialize car speeds and positions
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % 10 + 1;
        cars[i].position = i * 10;
    }
}

void print_cars(Car cars[], int num_cars) {
    // Print car positions
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: Speed = %d, Position = %d\n", i, cars[i].speed, cars[i].position);
    }
}

void update_cars(Car cars[], int num_cars) {
    // Update car positions based on speed
    for (int i = 0; i < num_cars; i++) {
        cars[i].position += cars[i].speed;
    }
}

int check_collision(Car car1, Car car2) {
    // Check if two cars collide
    if (car1.position == car2.position) {
        return 1;
    } else {
        return 0;
    }
}