//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

/* Function to move robot forward */
void move_forward() {
    printf("Moving forward\n");
}

/* Function to move robot backward */
void move_backward() {
    printf("Moving backward\n");
}

/* Function to turn robot left */
void turn_left() {
    printf("Turning left\n");
}

/* Function to turn robot right */
void turn_right() {
    printf("Turning right\n");
}

int main() {
    printf("Enter a movement command:\n");
    char command = getchar();

    /* Loop until user enters 'q' to quit */
    while(command != 'q') {
        switch(command) {
            case 'f':
                move_forward();
                break;
            case 'b':
                move_backward();
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            default:
                printf("Invalid command\n");
        }

        printf("Enter a movement command:\n");
        command = getchar();
    }

    printf("Quitting program...\n");
    return 0;
}