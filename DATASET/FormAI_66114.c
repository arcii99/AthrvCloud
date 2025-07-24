//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vehicle {
    int x; // x-coordinate
    int y; // y-coordinate
};

int main() {
    srand(time(NULL));

    struct Vehicle remoteControlledVehicle = {0, 0};
    printf("Remote control vehicle simulation program!\n\n");

    while(1) {
        int move = rand() % 4; // generates a random number in the range [0, 3]

        if (move == 0 && remoteControlledVehicle.y < 9) {
            remoteControlledVehicle.y++; // move up
        } else if (move == 1 && remoteControlledVehicle.x < 9) {
            remoteControlledVehicle.x++; // move right
        } else if (move == 2 && remoteControlledVehicle.y > 0) {
            remoteControlledVehicle.y--; // move down
        } else if (move == 3 && remoteControlledVehicle.x > 0) {
            remoteControlledVehicle.x--; // move left
        }

        printf("Vehicle coordinates: (%d, %d)\n", remoteControlledVehicle.x, remoteControlledVehicle.y);

        char moveAgain;
        printf("Do you want to move again? (y/n): ");
        scanf(" %c", &moveAgain);

        if (moveAgain == 'n') {
            break;
        }
    }

    printf("\nThanks for participating in the simulation program!\n");

    return 0;
}