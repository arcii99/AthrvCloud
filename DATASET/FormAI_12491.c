//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the maximum and minimum speed for the robot
#define MAX_SPEED 10
#define MIN_SPEED 1

// define the maximum and minimum size of the robot
#define MAX_SIZE 5
#define MIN_SIZE 1

// function to generate random speed and size for the robot
void generateSpeedAndSize(int* speed, int* size){
    srand(time(NULL));
    *speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    *size = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
}

// function to move the robot in a rectangular shape
void moveInRectangleShape(int speed, int size){

    // move in a straight line for the size of the robot
    for(int i = 0; i < size; i++){
        printf("Moved forward %d steps at speed %d\n", size, speed);
    }

    // turn right
    printf("Turned right\n");

    // move in a straight line for half the size of the robot
    int halfSize = size / 2;
    for(int i = 0; i < halfSize; i++){
        printf("Moved forward %d steps at speed %d\n", halfSize, speed);
    }

    // turn right
    printf("Turned right\n");

    // move in a straight line for the size of the robot
    for(int i = 0; i < size; i++){
        printf("Moved forward %d steps at speed %d\n", size, speed);
    }

    // turn right
    printf("Turned right\n");

    // move in a straight line for half the size of the robot
    for(int i = 0; i < halfSize; i++){
        printf("Moved forward %d steps at speed %d\n", halfSize, speed);
    }

    // turn right
    printf("Turned right\n");
}

int main(){

    int speed, size;

    generateSpeedAndSize(&speed, &size);

    moveInRectangleShape(speed, size);

    return 0;
}