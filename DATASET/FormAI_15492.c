//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are a space pilot on a mission to explore the outer reaches of the galaxy.\n");

    // generate a random distance to travel
    int distance = generateRandomNumber(1000, 5000);
    printf("Your mission is to travel %dkm to reach your destination.\n", distance);

    // generate a random amount of fuel
    int fuel = generateRandomNumber(500, 1000);
    printf("You have %dl of fuel in your spacecraft.\n", fuel);

    // start the adventure
    int currentDistance = 0;
    int currentFuel = fuel;
    while (currentDistance < distance && currentFuel > 0) {
        // generate a random amount of fuel to consume
        int fuelToConsume = generateRandomNumber(50, 100);

        // generate a random event
        int event = generateRandomNumber(1, 10);

        if (event <= 3) {
            printf("You encountered an asteroid field.\n");
            currentFuel -= fuelToConsume * 2;
        }
        else if (event <= 6) {
            printf("You encountered a group of friendly aliens.\n");
            currentFuel -= fuelToConsume / 2;
        }
        else {
            printf("Nothing eventful happened.\n");
            currentFuel -= fuelToConsume;
        }

        currentDistance += generateRandomNumber(50, 100);
        printf("You have traveled %dkm so far.\n", currentDistance);
    }

    // end the adventure
    if (currentDistance >= distance) {
        printf("Congratulations! You have reached your destination!\n");
    }
    else {
        printf("You ran out of fuel and couldn't complete your mission.\n");
    }

    return 0;
}