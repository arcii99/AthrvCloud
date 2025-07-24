//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int main()
{
    int robot_x = 0, robot_y = 0; // initial position of robot
    int direction, steps;
    srand(time(NULL));

    for(int i = 0; i < 50; i++) // to perform 50 movements
    {
        direction = rand() % 4 + 1; // choose a random direction
        steps = rand() % 5 + 1; // choose a random number of steps to take

        switch(direction)
        {
            case UP:
                robot_y += steps;
                printf("Robot moved %d steps up\n", steps);
                break;

            case DOWN:
                robot_y -= steps;
                printf("Robot moved %d steps down\n", steps);
                break;

            case LEFT:
                robot_x -= steps;
                printf("Robot moved %d steps left\n", steps);
                break;

            case RIGHT:
                robot_x += steps;
                printf("Robot moved %d steps right\n", steps);
                break;
        }

        printf("Current position of robot: (%d, %d)\n\n", robot_x, robot_y);
    }

    return 0;
}