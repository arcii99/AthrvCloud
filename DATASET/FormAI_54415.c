//FormAI DATASET v1.0 Category: Robot movement control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize variables
    int current_x = 0;
    int current_y = 0;
    char direction = 'N';

    //take user input for movement commands
    printf("Enter movement commands (F: Forward, L: Turn Left, R: Turn Right): ");
    char movements[100];
    fgets(movements, 100, stdin);

    //loop through each movement command
    int i = 0;
    while(movements[i] != '\n')
    {
        switch(movements[i])
        {
            case 'F':
                //move the robot forward in the current direction
                switch(direction)
                {
                    case 'N':
                        current_y++;
                        break;
                    case 'E':
                        current_x++;
                        break;
                    case 'S':
                        current_y--;
                        break;
                    case 'W':
                        current_x--;
                        break;
                }
                break;
            case 'L':
                //turn the robot left 90 degrees
                switch(direction)
                {
                    case 'N':
                        direction = 'W';
                        break;
                    case 'E':
                        direction = 'N';
                        break;
                    case 'S':
                        direction = 'E';
                        break;
                    case 'W':
                        direction = 'S';
                        break;
                }
                break;
            case 'R':
                //turn the robot right 90 degrees
                switch(direction)
                {
                    case 'N':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'S';
                        break;
                    case 'S':
                        direction = 'W';
                        break;
                    case 'W':
                        direction = 'N';
                        break;
                }
                break;
        }
        i++;
    }

    //print the final position and direction of the robot
    printf("Final Position: (%d, %d)\n", current_x, current_y);
    printf("Final Direction: %c\n", direction);

    return 0;
}