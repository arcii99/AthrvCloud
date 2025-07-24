//FormAI DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>   //header file for standard input and output
#include <stdlib.h>  //header file for standard library

void moveRobot(char direction);  //function prototype

int main() {
    char choice;
    printf("What direction would you like the robot to move?\n");
    printf("Please enter 'F' for forward, 'B' for backward, 'L' for left or 'R' for right: ");
    scanf("%c", &choice);  //user input
    fflush(stdin);  //flush input buffer to avoid errors
    
    moveRobot(choice);  //calling moveRobot function
    
    return 0;
}

void moveRobot(char direction) {
    printf("\n\nRobot is moving ");
    switch(direction) {
        case 'F':
            printf("forward.\n");
            break;
        case 'B':
            printf("backward.\n");
            break;
        case 'L':
            printf("to the left.\n");
            break;
        case 'R':
            printf("to the right.\n");
            break;
        default:
            printf("in an unknown direction.\n");
            break;
    }
    printf("\nThank you for using this program. Goodbye!\n");
}