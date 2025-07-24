//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
//It was late at night when the sound of screeching tires echoed through the empty street. 
//Sherlock Holmes was up and about to investigate as usual.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Remote Control Vehicle Simulation\n");

    //Create variables for the position and direction of the vehicle
    int x = 0;
    int y = 0;
    char direction = 'N';

    //Create a loop to simulate the movement of the vehicle
    while(1)
    {
        printf("Enter a command (f)orward, (r)ight, (l)eft, (q)uit: ");
        char command = getchar();

        //Check if the user wants to quit the simulation
        if(command == 'q')
        {
            printf("Exiting simulation...\n");
            break;
        }

        //Move the vehicle forward
        if(command == 'f')
        {
            //Move the vehicle one unit in the direction it is facing
            if(direction == 'N')
                y++;
            else if(direction == 'E')
                x++;
            else if(direction == 'S')
                y--;
            else if(direction == 'W')
                x--;

            //Print the new position of the vehicle
            printf("Moved forward to position (%d,%d)\n", x, y);
        }

        //Turn the vehicle right
        if(command == 'r')
        {
            //Change the direction of the vehicle based on its current direction
            if(direction == 'N')
                direction = 'E';
            else if(direction == 'E')
                direction = 'S';
            else if(direction == 'S')
                direction = 'W';
            else if(direction == 'W')
                direction = 'N';

            //Print the new direction of the vehicle
            printf("Turned right and facing %c\n", direction);
        }

        //Turn the vehicle left
        if(command == 'l')
        {
            //Change the direction of the vehicle based on its current direction
            if(direction == 'N')
                direction = 'W';
            else if(direction == 'W')
                direction = 'S';
            else if(direction == 'S')
                direction = 'E';
            else if(direction == 'E')
                direction = 'N';

            //Print the new direction of the vehicle
            printf("Turned left and facing %c\n", direction);
        }

        //Clear the input buffer
        while(getchar() != '\n');
    }

    return 0;
}