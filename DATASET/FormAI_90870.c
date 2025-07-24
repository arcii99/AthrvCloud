//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define MAX_CARS 5

typedef enum {LEFT, RIGHT} direction;

typedef struct {
    int position;
    direction dir;
} Car;

int count_cars(Car cars[]) {
    int count = 0;
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].position != -1) {
            count++;
        }
    }
    return count;
}

void move_car(Car *c) {
    if (c->dir == LEFT) {
        c->position--;
    } else {
        c->position++;
    }
}

void print_road(Car cars[]) {
    char road[ROAD_LENGTH+1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '-';
    }
    road[ROAD_LENGTH] = '\0';
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].position != -1) {
            road[cars[i].position] = '#';
        }
    }
    printf("%s\n", road);
}

void simulate_traffic_flow() {
    Car cars[MAX_CARS];
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = -1;
    }
    int num_cars = 0;
    srand(time(NULL)); // Seed random number generator
    while (1) {
        if (num_cars < MAX_CARS && (rand() % 100) < 50) {
            Car c;
            c.position = ROAD_LENGTH/2;
            c.dir = rand() % 2;
            cars[num_cars++] = c;
        }
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].position != -1) {
                if (cars[i].position == 0 || cars[i].position == ROAD_LENGTH-1) {
                    cars[i].position = -1; // Car has reached end of road
                } else {
                    // Check if space in front of car is clear
                    int blocked = 0;
                    for (int j = 0; j < MAX_CARS; j++) {
                        if (j != i && cars[j].position == cars[i].position + (cars[i].dir == LEFT ? -1 : 1)) {
                            blocked = 1;
                            break;
                        }
                    }
                    if (!blocked) {
                        move_car(&cars[i]);
                    }
                }
            }
        }
        print_road(cars);
        printf("Number of cars: %d\n", count_cars(cars));
        if (count_cars(cars) == 0) {
            break; // All cars have reached end of road
        }
    }
}

int main() {
    simulate_traffic_flow();
    return 0;
}