//FormAI DATASET v1.0 Category: Robot movement control ; Style: artistic
//Creating a Robot Movement Control Program
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Your robot will now enter an artistic dance performance.\n\n");

    int steps = 0;

    //Loop through 10 dance moves
    for (int i = 1; i <= 10; i++) {

        //Randomly choose a direction to move the robot
        int direction = rand() % 4;

        //Move the robot in the specified direction
        switch (direction) {
            case 0:
                printf("Step %d: Move the robot forward\n", i);
                break;
            case 1:
                printf("Step %d: Move the robot backward\n", i);
                break;
            case 2:
                printf("Step %d: Turn the robot left\n", i);
                break;
            case 3:
                printf("Step %d: Turn the robot right\n", i);
                break;
            default:
                printf("Invalid move\n");
        }

        //Wait for the robot to finish moving
        printf("Robot is moving...\n\n");
        for (int j = 1; j <= 3; j++) {
            printf("Step %d...\n", j);
        }
        printf("Robot movement completed.\n\n");

        //Keep track of the total number of steps taken
        steps += 3;
    }

    printf("The dance performance is complete!\n");
    printf("Your robot took a total of %d steps.\n", steps);

    return 0;
}