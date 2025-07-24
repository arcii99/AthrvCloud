//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed random number generator

    printf("Welcome to the cheerful GPS Navigation Simulation!\n");

    int destination = rand() % 6;  // Randomly assign a destination between 0 and 5
    printf("Your destination is: %d\n", destination);

    int current_location = rand() % 5;  // Randomly start at a location between 0 and 4
    printf("You are currently at location %d.\n", current_location);

    int distance = abs(destination - current_location);  // Calculate distance to destination
    printf("You are %d units away from your destination.\n", distance);

    while(current_location != destination) {
        if(current_location < destination) {
            current_location++;
        }
        else {
            current_location--;
        }

        distance = abs(destination - current_location);
        printf("You are now at location %d and %d units away from your destination.\n", current_location, distance);
    }

    printf("Congratulations, you have arrived at your destination!\n");

    return 0;
}