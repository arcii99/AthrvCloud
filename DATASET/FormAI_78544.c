//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    int current_x = rand() % 100; // randomly generate starting x-coordinate
    int current_y = rand() % 100; // randomly generate starting y-coordinate
    int destination_x = rand() % 100; // randomly generate destination x-coordinate
    int destination_y = rand() % 100; // randomly generate destination y-coordinate

    printf("Your current location is: (%d,%d)\n", current_x, current_y);
    printf("Your destination is: (%d,%d)\n", destination_x, destination_y);

    printf("Calculating the fastest route to your destination...\n");

    int remaining_distance = abs(destination_x - current_x) + abs(destination_y - current_y); // calculate remaining distance in grid units
    int steps = 0; // initialize step count to 0

    while (remaining_distance > 0) // continue looping until destination is reached
    {
        steps++; // increment step count

        if (destination_x > current_x) // if destination is to the right
        {
            current_x++; // move one unit to the right
            remaining_distance--; // reduce remaining distance
        }
        else if (destination_x < current_x) // if destination is to the left
        {
            current_x--; // move one unit to the left
            remaining_distance--; // reduce remaining distance
        }

        if (destination_y > current_y) // if destination is above
        {
            current_y++; // move one unit up
            remaining_distance--; // reduce remaining distance
        }
        else if (destination_y < current_y) // if destination is below
        {
            current_y--; // move one unit down
            remaining_distance--; // reduce remaining distance
        }

        printf("Step %d: Moved to: (%d,%d)\n", steps, current_x, current_y); // print current position
    }

    printf("You have arrived at your destination in %d steps!\n", steps); // print final step count

    return 0;
}