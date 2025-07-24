//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
// Welcome to the world of Remote Control Vehicle Simulation
// In this program, we will simulate a remote control toy car using C language

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the constants for car dimensions
#define CAR_WIDTH 10
#define CAR_HEIGHT 5

// Defining the constants for driving directions
#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'

// Defining the structure of our car
typedef struct {
    int x, y;    // position
    bool on;     // whether it is switched on or not
    char dir;    // current direction
} Car;

// This function will update the position of the car based on the driving direction
void move_car(Car *car) {
    switch (car->dir) {
        case FORWARD:
            car->y++;
            break;
        case BACKWARD:
            car->y--;
            break;
        case LEFT:
            car->x--;
            break;
        case RIGHT:
            car->x++;
            break;
    }
}

// This function will draw the car on the screen 
void draw_car(Car car) {
    int i, j;
    printf("\033[%d;%dH", car.y, car.x);
    printf("+");
    for (j = 0; j < CAR_WIDTH - 2; j++) {
        printf("-");
    }
    printf("+\n");
    for (i = 0; i < CAR_HEIGHT - 2; i++) {
        printf("\033[%d;%dH|", car.y + i + 1, car.x);
        printf(" ");
        for (j = 0; j < CAR_WIDTH - 4; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("\033[%d;%dH+", car.y + i + 1, car.x);
    for (j = 0; j < CAR_WIDTH - 2; j++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    Car car = {10, 10, true, FORWARD};  // Creating a new car object

    while (car.on) {
        system("clear");     // Clearing the screen

        // Checking if the car is at a valid position
        if (car.x < 0 || car.x + CAR_WIDTH > 80 || car.y < 0 || car.y + CAR_HEIGHT > 24) {
            printf("Car out of bounds, switching off...");
            car.on = false;
        }

        // Drawing the car on the screen
        draw_car(car);

        // Getting the user input for driving direction
        printf("\033[26;10HDrive the car using w, a, s, d keys\n");

        char input = getchar();

        // Updating the driving direction
        switch (input) {
            case FORWARD:
            case BACKWARD:
            case LEFT:
            case RIGHT:
                car.dir = input;
                break;
            default:
                break;
        }

        // Moving the car in the new direction
        move_car(&car);

        // Waiting for a moment before redrawing the screen
        usleep(50000);
    }

    return 0;
}