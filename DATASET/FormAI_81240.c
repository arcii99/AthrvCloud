//FormAI DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 100 // max number of steps the robot can take
#define MAX_DEGREE 360 // max degree the robot can rotate
#define MAX_X 100 // max distance the robot can travel in the x direction
#define MAX_Y 100 // max distance the robot can travel in the y direction

int main()
{
    // initialize variables
    int steps = rand() % MAX_STEPS + 1;
    int degree = rand() % MAX_DEGREE;
    int x = rand() % MAX_X + 1;
    int y = rand() % MAX_Y + 1;

    // generate random movement directions
    int move_x = rand() % 2;
    int move_y = rand() % 2;
    int turn_left = rand() % 2;
    int turn_right = rand() % 2;

    // print initial position and movements
    printf("Initial position: (%d, %d)\n", x, y);
    printf("Movement directions:\n");
    printf("Move in the x direction: %d\n", move_x);
    printf("Move in the y direction: %d\n", move_y);
    printf("Turn left: %d\n", turn_left);
    printf("Turn right: %d\n", turn_right);

    // perform random movements
    for (int i = 0; i < steps; i++)
    {
        if (move_x)
        {
            if (turn_left)
            {
                x--;
                printf("Step %d: moved left in the x direction\n", i+1);
            }
            else if (turn_right)
            {
                x++;
                printf("Step %d: moved right in the x direction\n", i+1);
            }
            else
            {
                printf("Step %d: no movement in the x direction\n", i+1);
            }
        }
        if (move_y)
        {
            if (turn_left)
            {
                y--;
                printf("Step %d: moved down in the y direction\n", i+1);
            }
            else if (turn_right)
            {
                y++;
                printf("Step %d: moved up in the y direction\n", i+1);
            }
            else
            {
                printf("Step %d: no movement in the y direction\n", i+1);
            }
        }
        if (turn_left)
        {
            degree = (degree - 90) % MAX_DEGREE;
            printf("Step %d: turned left to degree %d\n", i+1, degree);
        }
        if (turn_right)
        {
            degree = (degree + 90) % MAX_DEGREE;
            printf("Step %d: turned right to degree %d\n", i+1, degree);
        }
    }

    // print final position
    printf("Final position: (%d, %d)\n", x, y);

    return 0;
}