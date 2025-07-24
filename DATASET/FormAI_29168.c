//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funtion to move the robot forward
void forward(int dist) {
    printf("Moving forward %d cm\n", dist);
    //Code to move the robot forward
}

//Function to turn the robot left
void left(int angle) {
    printf("Turning left %d degrees\n", angle);
    //Code to turn the robot left
}

//Function to turn the robot right
void right(int angle) {
    printf("Turning right %d degrees\n", angle);
    //Code to turn the robot right
}

//Function to stop the robot
void stop() {
    printf("Stopping...\n");
    //Code to stop the robot
}

int main() {
    srand(time(NULL)); //Initializing random seed

    int distance = rand() % 101; //Generating a random distance between 0 and 100 cm
    int angle = rand() % 91; //Generating a random angle between 0 and 90 degrees
    int command = rand() % 4; //Generating a random command between 0 and 3

    printf("Distance: %d cm\n", distance);
    printf("Angle: %d degrees\n", angle);

    switch(command) {
        case 0:
            forward(distance);
            break;
        case 1:
            left(angle);
            break;
        case 2:
            right(angle);
            break;
        case 3:
            stop();
            break;
        default:
            printf("Invalid command\n");
    }

    return 0;
}