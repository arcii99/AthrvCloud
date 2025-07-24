//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10   //size of the grid
#define NUM_CARS 5     //number of cars on the road
#define MAX_SPEED 5    //maximum speed of a car

int grid[GRID_SIZE][GRID_SIZE]; //grid to represent the road
int car_positions[NUM_CARS];    //array to store the positions of the cars

//function to initialize the road with 0s
void initialize_grid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

//function to print the current state of the road
void print_grid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == -1) {
                printf("# ");
            } else if (grid[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

//function to add cars to the road
void add_cars() {
    int i, pos, count = 0;
    srand(time(NULL));
    while (count < NUM_CARS) {
        pos = rand() % GRID_SIZE;
        if (grid[0][pos] == 0) {
            grid[0][pos] = 1;
            car_positions[count] = pos;
            count++;
        }
    }
}

//function to move the cars on the road
void move_cars() {
    int i, j, pos, speed, distance, new_pos;
    for (i = 0; i < NUM_CARS; i++) {
        pos = car_positions[i];
        speed = rand() % MAX_SPEED + 1;
        distance = 0;
        for (j = pos + 1; j < GRID_SIZE; j++) {
            if (grid[0][j] != 0 || grid[1][j] != 0) {
                break;
            }
            distance++;
            if (distance >= speed) {
                new_pos = j;
                break;
            }
        }
        if (distance < speed) {
            new_pos = pos + distance;
        }
        grid[0][pos] = 0;
        grid[0][new_pos] = 1;
        car_positions[i] = new_pos;
    }
}

//main function
int main() {
    int i;
    initialize_grid();
    add_cars();
    print_grid();
    for (i = 0; i < 5; i++) {
        move_cars();
        print_grid();
    }
    return 0;
}