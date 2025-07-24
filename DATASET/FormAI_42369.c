//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
/* Remote Control Vehicle Simulation Program */
/* Author: Claude Shannon */

#include <stdio.h>
#include <stdlib.h>

/* Define constants for vehicle movement */
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

/* Define a function to simulate vehicle movement */
void move(int direction) {
    printf("Vehicle is moving ");
    switch(direction) {
        case LEFT:
            printf("left.\n");
            break;
        case RIGHT:
            printf("right.\n");
            break;
        case FORWARD:
            printf("forward.\n");
            break;
        case BACKWARD:
            printf("backward.\n");
            break;
        default:
            printf("in an unknown direction.\n");
    }
}

/* Define main function to read user input and control the vehicle */
int main() {
    int input;
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the arrow keys to control the vehicle.\n");
    printf("Press 'q' to quit the program.\n");
    while(1) {
        input = getchar();
        switch(input) {
            case 'q':
                printf("Exiting program...\n");
                exit(0);
                break;
            case '\033': /* Check for arrow keys */
                getchar(); /* Skip escape character */
                switch(getchar()) { /* Check for arrow direction */
                    case 'A':
                        move(FORWARD);
                        break;
                    case 'B':
                        move(BACKWARD);
                        break;
                    case 'C':
                        move(RIGHT);
                        break;
                    case 'D':
                        move(LEFT);
                        break;
                    default:
                        printf("Invalid input!\n");
                }
                break;
            default:
                printf("Invalid input!\n");
        }
    }
    return 0;
}