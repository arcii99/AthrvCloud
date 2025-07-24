//FormAI DATASET v1.0 Category: Robot movement control ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random movement for robot
int generate_movement() {
    srand(time(NULL));
    int movement = rand()%4;

    return movement;
}

int main() {
    int robot_position[2] = {0, 0}; // Starting position of robot
    int movement, steps;
    char direction[4][10] = {"Up", "Down", "Left", "Right"}; // Array to store directions

    printf("Robot Movement Control Program\n");

    // Loop to generate random movements for robot
    while(1) {
        movement = generate_movement(); // Generate random movement
        steps = (rand()%10) + 1; // Generate number of steps to take

        // Determine the direction and move the robot accordingly
        if(movement == 0) {
            printf("\nRobot moved %d steps %s", steps, direction[movement]);
            robot_position[0] += steps; // Move the robot up
        }
        else if(movement == 1) {
            printf("\nRobot moved %d steps %s", steps, direction[movement]);
            robot_position[0] -= steps; // Move the robot down
        }
        else if(movement == 2) {
            printf("\nRobot moved %d steps %s", steps, direction[movement]);
            robot_position[1] -= steps; // Move the robot left
        }
        else {
            printf("\nRobot moved %d steps %s", steps, direction[movement]);
            robot_position[1] += steps; // Move the robot right
        }

        printf("\nCurrent position: (%d,%d)\n", robot_position[0], robot_position[1]);

        // If the robot moves out of the allowed area, end the program
        if(robot_position[0] < -100 || robot_position[0] > 100 || robot_position[1] < -100 || robot_position[1] > 100) {
            printf("\nRobot is out of allowed area. Program ended.");
            break;
        }
    }

    return 0;
}