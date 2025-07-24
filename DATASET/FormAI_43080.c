//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SPEED 10
#define MAX_SPEED 30
#define MIN_DISTANCE 5
#define MAX_DISTANCE 50
#define MAX_CARS 20

struct car {
    int speed;
    int distance;
};

void init_cars(struct car *cars, int num_cars) {
    srand(time(0));
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
    }
}

void update_cars(struct car *cars, int num_cars) {
    int top_speed = 0;
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].speed > top_speed) {
            top_speed = cars[i].speed;
        }
    }
    for (int i = 0; i < num_cars; i++) {
        cars[i].distance -= (top_speed - cars[i].speed);
        if (i > 0) {
            int distance_to_prev = cars[i - 1].distance - cars[i].distance;
            if (distance_to_prev < 0) {
                cars[i].speed += distance_to_prev;
                if (cars[i].speed < 0) {
                    cars[i].speed = 0;
                }
            }
        }
    }
}

void print_cars(struct car *cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d - Speed: %d, Distance: %d\n", i, cars[i].speed, cars[i].distance);
    }
}

int main() {
    struct car cars[MAX_CARS];
    int num_cars = 5;
    init_cars(cars, num_cars);
    printf("Initial State:\n");
    print_cars(cars, num_cars);

    for (int i = 0; i < 10; i++) {
        printf("Tick %d:\n", i);
        update_cars(cars, num_cars);
        print_cars(cars, num_cars);
    }

    return 0;
}