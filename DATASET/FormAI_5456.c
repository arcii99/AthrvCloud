//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input = ' ';
    int x = 0, y = 0;
    printf("Welcome to paranoid C Robot Movement Control Program\n");
    printf("To move the robot press W for Forward, S for Backward, A for Left, and D for Right\n");
    printf("To stop the robot press X\n\n");

    while(input != 'X') {
        printf("Current position of robot: (%d, %d)\n", x, y);
        printf("Enter command: ");
        scanf("%c", &input);
        switch(input) {
            case 'W':
                printf("Moving Forward...\n");
                x += 1;
                break;
            case 'S':
                printf("Moving Backward...\n");
                x -= 1;
                break;
            case 'A':
                printf("Turning Left...\n");
                y -= 1;
                break;
            case 'D':
                printf("Turning Right...\n");
                y += 1;
                break;
            case 'X':
                printf("Stopping Robot...\n");
                break;
            default:
                printf("Invalid Input, try again.\n");
                break;
        }
        getchar(); // to consume newline from scanf
        printf("\n");
    }

    printf("Final position of robot: (%d, %d)\n", x, y);
    printf("Program Terminated.\n");
    return 0;
}