//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20

// Initialize the robot's position
int robotX = 0;
int robotY = 0;

// Prototypes for functions
void parseCommand(char *command);
void moveRobot(char direction);

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while(1) {
        // Prompt the user for input
        printf("Enter a command (up/down/left/right): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from the command
        strtok(command, "\n");

        // Parse the command and move the robot accordingly
        parseCommand(command);

        // Print the new position of the robot
        printf("New Robot Position: (%d,%d)\n", robotX, robotY);
    }

    return 0;
}

void parseCommand(char *command)
{
    if(strcmp(command, "up") == 0) {
        moveRobot('U');
    }
    else if(strcmp(command, "down") == 0) {
        moveRobot('D');
    }
    else if(strcmp(command, "left") == 0) {
        moveRobot('L');
    }
    else if(strcmp(command, "right") == 0) {
        moveRobot('R');
    }
    else {
        printf("Unknown command: %s\n", command);
    }
}

void moveRobot(char direction)
{
    switch(direction) {
        case 'U':
            robotY++;
            break;
        case 'D':
            robotY--;
            break;
        case 'L':
            robotX--;
            break;
        case 'R':
            robotX++;
            break;
        default:
            printf("Invalid direction: %c\n", direction);
            break;
    }
}