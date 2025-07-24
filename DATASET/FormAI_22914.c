//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 10 // maximum x-axis movement
#define MAX_Y 10 // maximum y-axis movement

int current_x = 0; // current x-axis location of robot
int current_y = 0; // current y-axis location of robot

void move_forward(int steps)
{
    int new_x = current_x + steps;
    if (new_x <= MAX_X)
    {
        current_x = new_x;
        printf("Moved forward %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
    else
    {
        printf("Oops! Can't move forward %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
}

void move_backward(int steps)
{
    int new_x = current_x - steps;
    if (new_x >= 0)
    {
        current_x = new_x;
        printf("Moved backward %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
    else
    {
        printf("Oops! Can't move backward %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
}

void move_left(int steps)
{
    int new_y = current_y - steps;
    if (new_y >= 0)
    {
        current_y = new_y;
        printf("Moved left %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
    else
    {
        printf("Oops! Can't move left %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
}

void move_right(int steps)
{
    int new_y = current_y + steps;
    if (new_y <= MAX_Y)
    {
        current_y = new_y;
        printf("Moved right %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
    else
    {
        printf("Oops! Can't move right %d steps. Current location: (%d, %d)\n", steps, current_x, current_y);
    }
}

int main()
{
    printf("Welcome to Robot Movement Control!\n\n");
    printf("Current location: (%d, %d)\n\n", current_x, current_y);

    // Let's move the robot around
    move_forward(5);
    move_left(2);
    move_backward(3);
    move_right(4);
    move_forward(10);

    printf("\nFinal location: (%d, %d)\n\n", current_x, current_y);

    printf("Thanks for using Robot Movement Control!\n");

    return EXIT_SUCCESS;
}