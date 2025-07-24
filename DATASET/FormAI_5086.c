//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include<stdio.h>

int main() {
    int x, y, move; // Declaring the variables for x and y position and movement option
    x = y = 0; // Initializing the position of the robot to (0, 0)
    printf("Robot Movement Control System!\n");
    printf("----------------------------\n");

    while(1) { // Infinite loop to keep the control system running
        printf("\nRobot Position: (%d,%d)\n", x, y); // Printing the current position of the robot
        printf("Enter 1 to move Up\nEnter 2 to move Down\nEnter 3 to move Left\nEnter 4 to move Right\nEnter 0 to Exit\n");
        scanf("%d", &move); // Reading user's choice for movement

        switch(move) { // Switch case to handle the different movement options
            case 0:
                printf("Exiting Robot Movement Control System!\n");
                return 0;

            case 1: // Move Up
                y++;
                printf("Moved Up!\n");
                break;

            case 2: // Move Down
                y--;
                printf("Moved Down!\n");
                break;

            case 3: // Move Left
                x--;
                printf("Moved Left!\n");
                break;

            case 4: // Move Right
                x++;
                printf("Moved Right!\n");
                break;

            default:
                printf("Invalid Movement Option!\n");
                break;
        }
    }
    return 0; // End of the program
}