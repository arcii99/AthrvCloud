//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define MAX_CARS 50
#define MIN_SPEED 1
#define MAX_SPEED 5
#define MAX_STEPS 100

typedef struct {
    int x, y;
    int speed;
    int distance;
    int next_move;
} Car;

int grid[GRID_SIZE][GRID_SIZE];
Car cars[MAX_CARS];
int num_cars = 0;

int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void init_grid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = -1;
        }
    }
}

void add_car(int x, int y, int speed) {
    if (num_cars < MAX_CARS) {
        Car car = {x, y, speed, 0, 0};
        cars[num_cars++] = car;
        grid[x][y] = num_cars - 1;
    }
}

void move_car(int i) {
    Car *car = &cars[i];
    int x = car->x;
    int y = car->y;
    int speed = car->speed;
    int distance = car->distance;

    // decrement distance to next car
    if (distance > 0) {
        distance--;
    }

    // check if car can move
    if (distance == 0) {
        int next_x = x;
        int next_y = y + speed;

        // check if car will go off the grid
        if (next_y >= GRID_SIZE) {
            next_y = GRID_SIZE - 1;
        }

        // check if there is a car blocking the way
        int next_distance = 0;
        int j;
        for (j = x; j <= next_x; j++) {
            if (grid[j][next_y] != -1) {
                int dist = cars[grid[j][next_y]].distance;
                if (dist >= next_distance) {
                    next_distance = dist + 1;
                }
            }
        }

        // update car's position
        car->x = next_x;
        car->y = next_y;
        car->next_move = rand_range(1, 5);
        car->distance = next_distance;
        grid[x][y] = -1;
        grid[next_x][next_y] = i;
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != -1) {
                printf("%d ", grid[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_grid();
    add_car(0, 0, rand_range(MIN_SPEED, MAX_SPEED));
    add_car(2, 2, rand_range(MIN_SPEED, MAX_SPEED));
    add_car(4, 4, rand_range(MIN_SPEED, MAX_SPEED));
    int i, j;
    for (i = 0; i < MAX_STEPS; i++) {
        printf("Step %d:\n", i + 1);
        for (j = 0; j < num_cars; j++) {
            move_car(j);
            print_grid();
        }
    }
    return 0;
}