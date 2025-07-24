//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a range
int generateRandom(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

int main()
{
    srand(time(0)); // To seed the random number generator

    // Initialize the vehicle parameters
    int batteryLevel = 100;
    int speed = 0;
    int distance = 0;
    int direction = 0; // 0 for forward, 1 for backward
    int maxSpeed = 30;
    int maxDistance = 1000;

    printf("C Remote Control Vehicle Simulation\n");

    // Start the simulation loop
    while (batteryLevel > 0 && distance < maxDistance)
    {
        // Randomly change the speed and direction
        if (generateRandom(0, 1) == 0) // Change direction
        {
            direction = !direction; // Flip direction
        }

        if (generateRandom(0, 1) == 0) // Change speed
        {
            int change = generateRandom(1, 5); // Maximum change in speed
            if (direction == 0) // Forward direction
            {
                speed = speed + change <= maxSpeed ? speed + change : maxSpeed;
            }
            else // Backward direction
            {
                speed = speed - change >= 0 ? speed - change : 0;
            }
        }

        // Update the distance and battery level based on speed and direction
        if (direction == 0) // Forward direction
        {
            distance += speed;
            batteryLevel -= speed / 10;
        }
        else // Backward direction
        {
            distance -= speed;
            batteryLevel -= speed / 5;
        }

        // Display the current status of the vehicle
        printf("Battery Level: %d%%, Speed: %d km/hr, Distance: %d meters, Direction: %s\n",
               batteryLevel, speed, distance, direction == 0 ? "Forward" : "Backward");
    }

    if (distance >= maxDistance)
    {
        printf("Vehicle has reached the destination.\n");
    }
    else
    {
        printf("Vehicle has run out of battery.\n");
    }

    return 0;
}