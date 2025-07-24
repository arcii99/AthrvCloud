//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the wait time between traffic light changes in seconds
#define WAIT_TIME 2

int main() {
    int carCount = 0; // Count the number of cars that have gone through the intersection

    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Loop through the traffic light pattern
    while (1) {

        // Red Light
        printf("\nRed light\n");
        sleep(WAIT_TIME);

        // Yellow Light
        printf("Yellow light\n");
        sleep(WAIT_TIME);

        // Green Light
        printf("Green light\n");

        int delay = rand() % 5 + 1; // Generate a random delay between 1 and 5 seconds
        sleep(delay);

        // Generate a random number of cars between 0 and 10
        int cars = rand() % 10;

        // Add the number of cars to the car count
        carCount += cars;

        // Output how many cars went through the intersection
        printf("%d cars went through the intersection\n", cars);

        // If there have been more than 100 cars, end the program
        if (carCount > 100) {
            break;
        }
    }

    printf("\nProgram has ended.\n");

    return 0;
}