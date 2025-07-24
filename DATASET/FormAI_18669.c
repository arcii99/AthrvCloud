//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 5

int num_cars = 0;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

typedef struct {
    int id;
    int speed;
    Direction direction;
} Car;

void init_cars(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].direction = rand() % 4;
        num_cars++;
    }
}

void print_cars(Car cars[]) {
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: Speed %d, Direction ", cars[i].id, cars[i].speed);
        switch (cars[i].direction) {
            case NORTH:
                printf("North\n");
                break;
            case EAST:
                printf("East\n");
                break;
            case SOUTH:
                printf("South\n");
                break;
            case WEST:
                printf("West\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }
    }
}

void update_speed(Car cars[]) {
    for (int i = 0; i < num_cars; i++) {
        // Check if car needs to slow down
        for (int j = 0; j < num_cars; j++) {
            if (i == j) {
                continue;
            }
            if (cars[i].direction == cars[j].direction) {
                if (cars[i].direction == NORTH || cars[i].direction == SOUTH) {
                    if (abs(cars[i].id - cars[j].id) < cars[i].speed) {
                        cars[i].speed = abs(cars[i].id - cars[j].id) - 1;
                    }
                } else {
                    if (abs(cars[i].id - cars[j].id) < cars[j].speed) {
                        cars[i].speed = abs(cars[i].id - cars[j].id) - 1;
                    }
                }
            }
        }
        // Check if car needs to speed up
        if (cars[i].speed < MAX_SPEED) {
            cars[i].speed++;
        }
        // Update car position
        if (cars[i].direction == NORTH) {
            cars[i].id -= cars[i].speed;
            if (cars[i].id < 0) {
                num_cars--;
                cars[i] = cars[num_cars];
            }
        } else if (cars[i].direction == EAST) {
            cars[i].id += cars[i].speed;
            if (cars[i].id > 99) {
                num_cars--;
                cars[i] = cars[num_cars];
            }
        } else if (cars[i].direction == SOUTH) {
            cars[i].id += cars[i].speed;
            if (cars[i].id > 99) {
                num_cars--;
                cars[i] = cars[num_cars];
            }
        } else if (cars[i].direction == WEST) {
            cars[i].id -= cars[i].speed;
            if (cars[i].id < 0) {
                num_cars--;
                cars[i] = cars[num_cars];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Car cars[MAX_CARS];

    init_cars(cars);

    while (num_cars > 0) {
        print_cars(cars);
        update_speed(cars);

        printf("Press Enter to continue...\n");
        getchar();
    }

    printf("All cars have left the simulation.\n");

    return 0;
}