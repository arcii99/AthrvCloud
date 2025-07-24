//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

int main(void) {
    char input;
    int x = 0, y = 0;
    printf("Welcome to the robot controller\n");
    do {
        printf("Enter your move (F for Forward, B for Backward, L for Left, R for Right): ");
        scanf(" %c", &input);

        switch(input) {
            case FORWARD:
                y++;
                printf("Robot moves Forward\n");
                break;
            case BACKWARD:
                y--;
                printf("Robot moves Backward\n");
                break;
            case LEFT:
                x--;
                printf("Robot moves Left\n");
                break;
            case RIGHT:
                x++;
                printf("Robot moves Right\n");
                break;
            default:
                printf("Invalid input\n");
        }
        printf("Robot is at position (%d, %d)\n", x, y);
    } while(input != 'Q');
    printf("Thank you for using the robot controller\n");
    return 0;
}