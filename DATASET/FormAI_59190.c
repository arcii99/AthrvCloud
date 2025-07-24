//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// define structures for the remote control vehicle
typedef struct {
    int x, y; // position of the vehicle
    int speed; // speed of the vehicle
    char direction; // direction vehicle is facing
} RCVehicle;

// function to move the vehicle
void moveVehicle(RCVehicle *vehicle) {
    switch(tolower(vehicle->direction)) {
        case 'n':
            vehicle->y -= vehicle->speed;
            break;
        case 'e':
            vehicle->x += vehicle->speed;
            break;
        case 's':
            vehicle->y += vehicle->speed;
            break;
        case 'w':
            vehicle->x -= vehicle->speed;
            break;
        default:
            break;
    }
}

// main function to control the simulation
int main(void) {
    // create the vehicle and set its initial state
    RCVehicle myVehicle;
    myVehicle.x = 0;
    myVehicle.y = 0;
    myVehicle.speed = 1;
    myVehicle.direction = 'n';

    // print initial state of the vehicle
    printf("Vehicle initialized at (%d,%d) facing %c.\n", myVehicle.x, myVehicle.y, myVehicle.direction);

    // loop to take user inputs
    while(1) {
        // read user input
        char input[100];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // check if the user wants to quit
        if(strcmp(input, "exit") == 0) {
            break;
        }

        // check if the user wants to change the speed of the vehicle
        else if(strncmp(input, "speed ", 6) == 0) {
            myVehicle.speed = atoi(input+6);
            printf("Speed set to %d.\n", myVehicle.speed);
        }

        // check if the user wants to change the direction of the vehicle
        else if(strncmp(input, "turn ", 5) == 0) {
            myVehicle.direction = tolower(input[5]);
            printf("Vehicle turned to face %c.\n", myVehicle.direction);
        }

        // check if the user wants to move the vehicle
        else if(strcmp(input, "move") == 0) {
            moveVehicle(&myVehicle);
            printf("Vehicle moved to (%d,%d).\n", myVehicle.x, myVehicle.y);
        }

        // if the input is invalid, print an error message
        else {
            printf("Invalid command.\n");
        }
    }

    // print final state of the vehicle
    printf("Vehicle stopped at (%d,%d) facing %c.\n", myVehicle.x, myVehicle.y, myVehicle.direction);

    return 0;
}