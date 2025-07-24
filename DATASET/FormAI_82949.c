//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int batteryLevel = 100;
    int distanceTraveled = 0;
    int errorsEncountered = 0;
    int maxDistance = 1000;
    int minDistance = 1;

    srand(time(NULL)); // initialize random number generator

    for (int i = 0; i < 10; i++) {
        int randomDistance = rand() % (maxDistance + 1 - minDistance) + minDistance; // generate random distance
        printf("Moving robot %d meters...\n", randomDistance);
        distanceTraveled += randomDistance; // add to total distance traveled
        batteryLevel -= randomDistance / 10; // subtract from battery level
        if (batteryLevel <= 0) { // check if battery is dead
            printf("Robot stopped due to dead battery.\n");
            break;
        }
        int randomError = rand() % 100 + 1; // generate random error code
        if (randomError <= 5) { // 5% chance of error occurring
            printf("Error encountered: %d. Stopping robot.\n", randomError);
            errorsEncountered++;
            break;
        }
    }

    printf("Robot traveled a total of %d meters and encountered %d errors.\n", distanceTraveled, errorsEncountered);

    return 0;
}