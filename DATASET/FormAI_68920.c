//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROAD_LENGTH 100
#define MAX_SPEED 10
#define MIN_SPEED 1
#define VARIATION 4
#define MAX_CARS 10

typedef enum { LEFT, RIGHT } Direction;

typedef struct {
    int position;
    int speed;
    int next_car_distance;
} Car;

void print_road(Car cars[]);
void move_cars(Car cars[]);
void accelerate(Car cars[]);
void decelerate(Car cars[]);
void update_distances(Car cars[]);
void spawn_cars(Direction direction, Car cars[]);

int main() {
    srand(time(NULL));
    Car cars[ROAD_LENGTH] = {0};
    int time_counter = 0;
    Direction direction = LEFT;

    while (1) {
        if (time_counter % 10 == 0) {
            spawn_cars(direction, cars);
        }
        print_road(cars);
        move_cars(cars);
        usleep(10000);
        time_counter++;
    }
    return 0;
}

void print_road(Car cars[]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (cars[i].speed) {
            printf("x");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

void move_cars(Car cars[]) {
    accelerate(cars);
    decelerate(cars);
    update_distances(cars);
    for (int i = ROAD_LENGTH - 1; i >= 0; i--) {
        if (cars[i].speed > 0) {
            cars[i + cars[i].speed] = cars[i];
            if (i + cars[i].speed != i) {
                cars[i] = (Car) {0};
            }
        }
    }
}

void accelerate(Car cars[]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (cars[i].speed < MAX_SPEED && cars[i].next_car_distance >= cars[i].speed) {
            cars[i].speed++;
        }
    }
}

void decelerate(Car cars[]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (cars[i].speed > 0) {
            int distance_to_next_car = cars[i].next_car_distance - 1;
            for (int j = 1; j <= VARIATION && i + j < ROAD_LENGTH; j++) {
                if (cars[i + j].speed > j && cars[i + j].next_car_distance <= distance_to_next_car) {
                    distance_to_next_car = cars[i + j].next_car_distance - 1;
                }
            }
            if (cars[i].speed > distance_to_next_car) {
                cars[i].speed = distance_to_next_car;
            }
        }
    }
}

void update_distances(Car cars[]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        cars[i].next_car_distance = ROAD_LENGTH;
        for (int j = i + 1; j < ROAD_LENGTH && cars[j].speed == 0; j++) {
            cars[i].next_car_distance++;
        }
    }
}

void spawn_cars(Direction direction, Car cars[]) {
    if (direction == LEFT) {
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].speed == 0) {
                cars[i] = (Car) {0, MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED + 1), ROAD_LENGTH - 1 - i};
            }
        }
    } else {
        for (int i = ROAD_LENGTH - 1; i >= ROAD_LENGTH - MAX_CARS; i--) {
            if (cars[i].speed == 0) {
                cars[i] = (Car) {0, MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED + 1), i};
            }
        }
    }
}