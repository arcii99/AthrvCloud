//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int distance = 0; // initialize distance to 0
    int battery = 100; // initialize battery to 100
    int position = 0; // initialize position to 0
    int speed = 0; // initialize speed to 0
    int acceleration = 0; // initialize acceleration to 0

    // loop until the battery dies or the distance is reached
    while (battery > 0 && distance < 500) {
        // randomly generate a speed between 0 and 10
        speed = rand() % 11;
        // randomly generate an acceleration between -5 and 5
        acceleration = rand() % 11 - 5;
        // update the position based on the speed and acceleration
        position += speed + acceleration;
        // calculate the remaining distance to the endpoint
        distance = 500 - position;
        // decrement the battery depending on the speed and acceleration
        battery -= speed + acceleration;

        // print out the current status of the vehicle
        printf("Distance remaining: %d meters\n", distance);
        printf("Battery remaining: %d percent\n", battery);
        printf("Speed: %d meters per second\n", speed);
        printf("Acceleration: %d meters per second squared\n", acceleration);
        printf("Position: %d meters from the starting point\n\n", position);
    }

    // if the battery died before the distance was reached
    if (battery <= 0) {
        printf("Battery died before reaching the endpoint.\n");
    }
    // if the distance was reached before the battery died
    else {
        printf("Endpoint reached successfully!\n");
    }

    return 0;
}