//FormAI DATASET v1.0 Category: Robot movement control ; Style: random
#include<stdio.h>

// Function to move the robot
void moveRobot(char direction, int distance){
    // Code to send movement commands to the robot
    printf("Moving the robot %d meters %c\n", distance, direction);
}

// Main function to control the movement of the robot
int main(){
    char command;
    int distance;
    printf("Welcome to the robot movement control program!\n");
    printf("Enter the commands to move the robot:\n");
    do{
        // Reading the command from the user
        printf("Enter the command (F/B/L/R) and distance in meters (0-1000) separated by a space: ");
        scanf("%c %d", &command, &distance);

        // Processing the command
        if(command == 'F'){
            // Move the robot forward
            moveRobot('F', distance);
        }
        else if(command == 'B'){
            // Move the robot backward
            moveRobot('B', distance);
        }
        else if(command == 'L'){
            // Move the robot left
            moveRobot('L', distance);
        }
        else if(command == 'R'){
            // Move the robot right
            moveRobot('R', distance);
        }
        else{
            // Invalid command
            printf("Invalid command. Please try again.\n");
        }
        // Clear the input buffer
        fflush(stdin);

    }while(command != 'Q');
    // Q is used to quit the program

    printf("Exiting the robot movement control program.\n");
    return 0;
}