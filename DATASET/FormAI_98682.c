//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[50]; 
    int droneX = 0, droneY = 0; 

    printf("Welcome to the C Drone Remote Control Program!\n\n");
    printf("You are the commander of the drone and you need to navigate the drone through the medieval maze to reach the castle. \n\n");
    printf("Enter your commands below:\n\n");

    while(1) // infinite loop until the drone reaches the castle
    {
        printf("X:%d Y:%d > ", droneX, droneY); //current location of the drone
        
        fgets(command, 50, stdin); // get the user input
 
        if(strncmp(command, "north", 5) == 0) // move north
        {
            droneY++;
            printf("Moving north...\n\n");
        }
        else if(strncmp(command, "south", 5) == 0) // move south
        {
            droneY--;
            printf("Moving south...\n\n");
        }
        else if(strncmp(command, "west", 4) == 0) // move west
        {
            droneX--;
            printf("Moving west...\n\n");
        }
        else if(strncmp(command, "east", 4) == 0) // move east
        {
            droneX++;
            printf("Moving east...\n\n");
        }
        else if(strncmp(command, "fire", 4) == 0) // fire cannon
        {
            printf("Firing the cannon!\n\n");
        }
        else if(strncmp(command, "quit", 4) == 0) // quit the program
        {
            printf("Quitting the program.\n");
            break;
        }
        else // invalid command
        {
            printf("Invalid command!\n\n");
        }
 
        if(droneX == 9 && droneY == 9) // drone reaches the castle
        {
            printf("Congratulations! You have successfully navigated the drone to the castle!\n");
            break;
        }
    }
    return 0;
}