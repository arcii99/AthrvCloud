//FormAI DATASET v1.0 Category: Robot movement control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x_pos = 0, y_pos = 0; // global variables to store robot's position

void move_robot(char direction) // function to move the robot
{
    switch(direction)
    {
        case 'U':
            y_pos++;
            printf("Moved up!\n");
            break;
        case 'D':
            y_pos--;
            printf("Moved down!\n");
            break;
        case 'L':
            x_pos--;
            printf("Moved left!\n");
            break;
        case 'R':
            x_pos++;
            printf("Moved right!\n");
            break;
        default:
            printf("Invalid direction!\n");
    }
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    printf("Starting position: (%d, %d)\n", x_pos, y_pos);
    
    int i;
    for(i=0; i<10; i++) // move the robot randomly 10 times
    {
        int dir = rand() % 4; // generate a random number between 0 and 3
        switch(dir)
        {
            case 0:
                move_robot('U');
                break;
            case 1:
                move_robot('D');
                break;
            case 2:
                move_robot('L');
                break;
            case 3:
                move_robot('R');
                break;
        }
    }
    
    printf("Final position: (%d, %d)\n", x_pos, y_pos);
    
    return 0;
}