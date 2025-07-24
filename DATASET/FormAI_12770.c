//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define SIMULATION_SPEED 1000 // milliseconds
#define MAX_DISTANCE 10 // meters
#define MAX_SPEED 5 // meters per second
#define MAX_TURNS 10

int main() {
    srand(time(NULL));
    char direction;
    int distance = 0;
    int speed = 0;
    int turns = 0;
    bool isMoving = false;
    bool isTurning = false;

    printf("Welcome to Remote Control Vehicle Simulation.\n");
    printf("WARNING: This program is to be used for paranoid style simulation only.\n");
    printf("The vehicle will move randomly in four directions (up, down, left, right).\n");
    printf("You can remotely control the vehicle's movement with the following keys:\n");
    printf("w: move up\ns: move down\na: move left\nd: move right\n");
    printf("You have a maximum of 10 turns to observe the vehicle's movement and report back.\n");

    while (turns <= MAX_TURNS) {
        if (!isMoving) {
            speed = rand() % MAX_SPEED + 1;
            isMoving = true;
        }

        if (!isTurning) {
            direction = rand() % 4;
            isTurning = true;
        }

        switch (direction) {
            case 0: // up
                printf("Vehicle moved up ");
                distance += speed;
                break;
            case 1: // down
                printf("Vehicle moved down ");
                distance += speed;
                break;
            case 2: // left
                printf("Vehicle moved left ");
                distance += speed;
                break;
            case 3: // right
                printf("Vehicle moved right ");
                distance += speed;
                break;
        }

        printf("%d meters with a speed of %d meters per second.\n", distance, speed);
        printf("Enter a letter to control the vehicle's movement: ");

        char input;
        input = getchar();

        if (input == UP) {
            printf("Vehicle moved up.\n");
            distance += 1;
        } else if (input == DOWN) {
            printf("Vehicle moved down.\n");
            distance -= 1;
        } else if (input == LEFT) {
            printf("Vehicle moved left.\n");
            distance -= 1;
        } else if (input == RIGHT) {
            printf("Vehicle moved right.\n");
            distance += 1;
        }

        if (distance >= MAX_DISTANCE) {
            printf("Vehicle has reached its maximum distance of %d meters.\n", MAX_DISTANCE);
            break;
        }

        isMoving = false;
        isTurning = false;
        turns++;
        printf("Turns left: %d\n", MAX_TURNS - turns);
        printf("-------------------------\n");
        getchar(); // clear input buffer
        sleep(SIMULATION_SPEED); // pause for SIMULATION_SPEED amount of milliseconds
    }

    printf("Simulation has ended. Please return the vehicle to its original location.\n");

    return 0;
}