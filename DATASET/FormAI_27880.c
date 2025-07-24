//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the RC vehicle simulation program!\n");

    // initialize random seed
    srand(time(NULL));

    // set initial position of vehicle
    int x = 0;
    int y = 0;

    // set initial direction of vehicle (0 = north, 1 = east, 2 = south, 3 = west)
    int direction = 0;

    // set initial battery life
    int battery_life = 100;

    // print initial status of vehicle
    printf("Position: (%d, %d)\n", x, y);
    printf("Direction: North\n");
    printf("Battery Life: %d%%\n", battery_life);

    // main loop to control vehicle movement
    while (battery_life > 0) {
        // generate random number to determine direction of movement
        int move_direction = rand() % 4;

        // update direction of vehicle
        if (move_direction == 0) {
            direction = 0; // north
            printf("Moving North\n");
        } else if (move_direction == 1) {
            direction = 1; // east
            printf("Moving East\n");
        } else if (move_direction == 2) {
            direction = 2; // south
            printf("Moving South\n");
        } else {
            direction = 3; // west
            printf("Moving West\n");
        }

        // generate random number to determine distance of movement
        int move_distance = rand() % 11;

        // update position of vehicle based on direction and distance of movement
        if (direction == 0) {
            y += move_distance;
        } else if (direction == 1) {
            x += move_distance;
        } else if (direction == 2) {
            y -= move_distance;
        } else {
            x -= move_distance;
        }

        // decrease battery life by 1% for each movement
        battery_life--;

        // print updated status of vehicle
        printf("Position: (%d, %d)\n", x, y);
        if (direction == 0) {
            printf("Direction: North\n");
        } else if (direction == 1) {
            printf("Direction: East\n");
        } else if (direction == 2) {
            printf("Direction: South\n");
        } else {
            printf("Direction: West\n");
        }
        printf("Battery Life: %d%%\n", battery_life);
    }

    // print final status of vehicle
    printf("Out of Battery Life. Game Over.\n");

    return 0;
}