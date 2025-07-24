//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize variables
    int current_location = 0;
    int destination = 0;
    int distance = 0;
    char direction;

    // Ask for starting location
    printf("Please enter your starting location (0-100): ");
    scanf("%d", &current_location);

    // Ask for destination
    printf("Please enter your destination (0-100): ");
    scanf("%d", &destination);

    // Calculate distance
    distance = abs(destination - current_location);

    // Determine direction
    if (current_location < destination)
    {
        direction = 'E';
    }
    else
    {
        direction = 'W';
    }

    // Output directions
    printf("Drive %d miles %c.\n", distance, direction);

    return 0;
}