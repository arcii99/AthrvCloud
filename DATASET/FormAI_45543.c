//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0; // x position of the robot
    int y = 0; // y position of the robot
    int direction = 0; // direction of the robot, 0: up, 1: right, 2: down, 3: left

    srand(time(NULL)); // seed random number generator with current time

    printf("Starting position: x=%d, y=%d\n", x, y);

    // loop to move the robot
    for(int i = 0; i < 50; i++)
    {
        int move = rand() % 4; // generate random move, 0: forward, 1: turn right, 2: turn left, 3: backward
        
        // move the robot
        if(move == 0) // forward
        {
            switch(direction)
            {
                case 0: y++; break; // up
                case 1: x++; break; // right
                case 2: y--; break; // down
                case 3: x--; break; // left
            }
        }
        else if(move == 1) // turn right
        {
            direction++;
            if(direction == 4) direction = 0;
        }
        else if(move == 2) // turn left
        {
            direction--;
            if(direction == -1) direction = 3;
        }
        else if(move == 3) // backward
        {
            switch(direction)
            {
                case 0: y--; break; // up
                case 1: x--; break; // right
                case 2: y++; break; // down
                case 3: x++; break; // left
            }
        }

        printf("Move %d: ", i+1);
        switch(move)
        {
            case 0: printf("Forward "); break;
            case 1: printf("Turn Right "); break;
            case 2: printf("Turn Left "); break;
            case 3: printf("Backward "); break;
        }
        printf("New position: x=%d, y=%d, direction=%d\n", x, y, direction);
    }

    printf("Final position: x=%d, y=%d, direction=%d\n", x, y, direction);

    return 0;
}