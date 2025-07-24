//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TICKS 1000
#define CAR_SPAWN_PROB 0.2

enum Direction { NORTH, EAST, SOUTH, WEST };

struct Car {
    int id;
    int x;
    int y;
    enum Direction dir;
};

void init_cars(struct Car* cars, int num_cars);
void move_cars(struct Car* cars, int num_cars);
void print_map(struct Car* cars, int num_cars);

int main() {
    srand(time(NULL)); // Initialize random seed

    struct Car cars[MAX_CARS];
    int num_cars = 0;

    init_cars(cars, MAX_CARS);

    for (int i = 0; i < MAX_TICKS; i++) {
        printf("Tick %d:\n", i);
        move_cars(cars, num_cars);
        print_map(cars, num_cars);
        printf("\n");

        if (rand() < RAND_MAX * CAR_SPAWN_PROB && num_cars < MAX_CARS) {
            cars[num_cars].id = num_cars;
            cars[num_cars].x = rand() % 10;
            cars[num_cars].y = rand() % 10;
            cars[num_cars].dir = rand() % 4;
            num_cars++;
        }
    }

    return 0;
}

// Initialize cars at random locations and directions
void init_cars(struct Car* cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].x = rand() % 10;
        cars[i].y = rand() % 10;
        cars[i].dir = rand() % 4;
    }
}

// Move cars one step according to their direction
void move_cars(struct Car* cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        switch (cars[i].dir) {
            case NORTH: cars[i].y--; break;
            case EAST: cars[i].x++; break;
            case SOUTH: cars[i].y++; break;
            case WEST: cars[i].x--; break;
        }

        // Wrap around the edges of the map
        if (cars[i].x < 0) cars[i].x += 10;
        if (cars[i].y < 0) cars[i].y += 10;
        if (cars[i].x >= 10) cars[i].x -= 10;
        if (cars[i].y >= 10) cars[i].y -= 10;
    }
}

// Print a map of cars and their positions
void print_map(struct Car* cars, int num_cars) {
    char map[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '-';
        }
    }

    for (int i = 0; i < num_cars; i++) {
        char symbol;

        switch (cars[i].dir) {
            case NORTH: symbol = '^'; break;
            case EAST: symbol = '>'; break;
            case SOUTH: symbol = 'v'; break;
            case WEST: symbol = '<'; break;
        }

        map[cars[i].y][cars[i].x] = symbol;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}