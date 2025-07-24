//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

// Define constants for the simulation
#define GRID_HEIGHT 10
#define GRID_WIDTH 10

#define FORWARD 'F'
#define LEFT 'L'
#define RIGHT 'R'
#define QUIT 'Q'

// Define a structure for the grid
typedef struct {
    char cells[GRID_WIDTH][GRID_HEIGHT];
} Grid;

// Define a structure for the vehicle
typedef struct {
    int x;
    int y;
    char direction;
} Vehicle;

// Define a function to initialize the grid
void initializeGrid(Grid *grid) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid->cells[i][j] = '.';
        }
    }
}

// Define a function to initialize the vehicle
void initializeVehicle(Vehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->direction = 'N';
}

// Define a function to print the grid with the vehicle
void printGrid(Grid *grid, Vehicle *vehicle) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (i == vehicle->y && j == vehicle->x) {
                printf("%c", vehicle->direction);
            } else {
                printf("%c", grid->cells[i][j]);
            }
        }
        printf("\n");
    }
}

// Define a function to move the vehicle forward
void moveForward(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            if (vehicle->y > 0) {
                vehicle->y--;
            }
            break;
        case 'S':
            if (vehicle->y < GRID_HEIGHT - 1) {
                vehicle->y++;
            }
            break;
        case 'E':
            if (vehicle->x < GRID_WIDTH - 1) {
                vehicle->x++;
            }
            break;
        case 'W':
            if (vehicle->x > 0) {
                vehicle->x--;
            }
            break;
    }
}

// Define a function to turn the vehicle left
void turnLeft(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->direction = 'W';
            break;
        case 'S':
            vehicle->direction = 'E';
            break;
        case 'E':
            vehicle->direction = 'N';
            break;
        case 'W':
            vehicle->direction = 'S';
            break;
    }
}

// Define a function to turn the vehicle right
void turnRight(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->direction = 'E';
            break;
        case 'S':
            vehicle->direction = 'W';
            break;
        case 'E':
            vehicle->direction = 'S';
            break;
        case 'W':
            vehicle->direction = 'N';
            break;
    }
}

int main() {
    Grid grid;
    Vehicle vehicle;
    initializeGrid(&grid);
    initializeVehicle(&vehicle);
    printf("Press 'F' to move forward, 'L' to turn left, 'R' to turn right, and 'Q' to quit:\n");
    printGrid(&grid, &vehicle);
    while (true) {
        char input;
        scanf(" %c", &input);
        switch (input) {
            case FORWARD:
                moveForward(&vehicle);
                break;
            case LEFT:
                turnLeft(&vehicle);
                break;
            case RIGHT:
                turnRight(&vehicle);
                break;
            case QUIT:
                goto end;
        }
        printGrid(&grid, &vehicle);
    }
    end:
    printf("Goodbye!\n");
    return 0;
}