//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables to hold drone status
    int battery = 100;
    int altitude = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Print initial drone status
    printf("Battery: %d%%\nAltitude: %d meters\nPitch: %d degrees\nRoll: %d degrees\nYaw: %d degrees\n\n", battery, altitude, pitch, roll, yaw);

    // Start remote control loop
    while (1) {
        // Randomly generate new pitch, roll, and yaw values
        pitch += rand() % 21 - 10;
        roll += rand() % 21 - 10;
        yaw += rand() % 21 - 10;

        // Check for out-of-bounds pitch, roll, and yaw values
        if (pitch > 45) {
            pitch = 45;
        } else if (pitch < -45) {
            pitch = -45;
        }
        if (roll > 45) {
            roll = 45;
        } else if (roll < -45) {
            roll = -45;
        }
        if (yaw > 180) {
            yaw = -180;
        } else if (yaw < -180) {
            yaw = 180;
        }

        // Randomly generate new altitude value
        altitude += rand() % 11 - 5;

        // Check for out-of-bounds altitude value
        if (altitude > 100) {
            altitude = 100;
        } else if (altitude < 0) {
            altitude = 0;
        }

        // Decrement battery level
        battery--;

        // Print updated drone status
        printf("Battery: %d%%\nAltitude: %d meters\nPitch: %d degrees\nRoll: %d degrees\nYaw: %d degrees\n\n", battery, altitude, pitch, roll, yaw);

        // Check if battery is low
        if (battery == 20) {
            printf("WARNING: Battery low!\n\n");
        }

        // Check if battery is dead
        if (battery == 0) {
            printf("ERROR: Drone shutting down due to dead battery!\n\n");
            break;
        }

        // Wait 1 second before looping again
        sleep(1);
    }

    return 0;
}