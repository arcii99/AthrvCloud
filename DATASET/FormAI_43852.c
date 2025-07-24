//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int get_random_number(int max_value)              // function to generate random numbers within a given range
{
    return rand() % max_value;
}

int main()
{
    int x_pos = 0;                                // initial x-position of robot
    int y_pos = 0;                                // initial y-position of robot
    int direction = 0;                            // initial direction of robot (0=N, 1=E, 2=S, 3=W)
    int steps = 0;                                // steps taken by robot
    int max_steps = 100;                          // maximum steps allowed to take by robot
    int max_x_pos = 10;                           // maximum x-position on grid
    int max_y_pos = 10;                           // maximum y-position on grid

    srand(time(NULL));                            // seeding random number generator with current time

    printf("Welcome to Retro Robot Movement Control Program!\n\n");

    while (steps < max_steps)                      // loop to control robot movement
    {
        int direction_change = get_random_number(2);  // generate random number to decide whether to change direction or not

        if (direction_change == 1)                   // if number is 1, change direction
        {
            int new_direction = get_random_number(3);  // generate a random number to decide new direction

            while ((new_direction < direction - 1) || (new_direction > direction + 1))
            {
                new_direction = get_random_number(3);
            }

            direction = new_direction;
        }

        int step_size = get_random_number(3) + 1;   // generate random number to decide step size

        switch (direction)                          // update x and y positions according to direction and step size
        {
            case 0:
                y_pos += step_size;
                break;

            case 1:
                x_pos += step_size;
                break;

            case 2:
                y_pos -= step_size;
                break;

            case 3:
                x_pos -= step_size;
                break;
        }

        if (x_pos > max_x_pos)                      // if robot reaches boundary, reset position to boundary
        {
            x_pos = max_x_pos;
        }

        if (x_pos < 0)
        {
            x_pos = 0;
        }

        if (y_pos > max_y_pos)
        {
            y_pos = max_y_pos;
        }

        if (y_pos < 0)
        {
            y_pos = 0;
        }

        printf("Robot is at position (%d, %d) facing ", x_pos, y_pos);

        switch(direction)
        {
            case 0:
                printf("North\n");
                break;
            case 1:
                printf("East\n");
                break;
            case 2:
                printf("South\n");
                break;
            case 3:
                printf("West\n");
                break;
        }

        steps++;                                      // increment steps taken by robot
    }

    printf("\nRobot has completed %d steps. Program terminated!", steps);

    return 0;
}