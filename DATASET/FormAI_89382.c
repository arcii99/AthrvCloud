//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int currentLocation[2] = {0, 0};
    int destination[2] = {rand() % 100, rand() % 100};
    char directions[4][10] = {"north", "south", "east", "west"};

    printf("*** Welcome to GPS Navigation Simulation! ***\n");
    printf("Your current location is (%d, %d)\n", currentLocation[0], currentLocation[1]);
    printf("Your destination is (%d, %d)\n", destination[0], destination[1]);

    while (currentLocation[0] != destination[0] || currentLocation[1] != destination[1]) {
        int moveDirection = rand() % 4;
        int moveDistance = rand() % 10 + 1;

        printf("Move %d km to the %s\n", moveDistance, directions[moveDirection]);

        switch (moveDirection) {
            case 0:
                currentLocation[0] += moveDistance;
                break;
            case 1:
                currentLocation[0] -= moveDistance;
                break;
            case 2:
                currentLocation[1] += moveDistance;
                break;
            case 3:
                currentLocation[1] -= moveDistance;
                break;
        }

        printf("Your current location is (%d, %d)\n", currentLocation[0], currentLocation[1]);
    }

    printf("You have arrived at your destination!\n");
    printf("*** End of GPS Navigation Simulation! ***\n");

    return 0;
}