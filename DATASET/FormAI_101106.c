//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* conspiracy;

    srand(time(NULL)); // initialize random seed

    switch (rand() % 5) { // choose a random conspiracy theory
        case 0:
            conspiracy = "The moon landing was faked by the government.";
            break;
        case 1:
            conspiracy = "Chemtrails are being used to control the population.";
            break;
        case 2:
            conspiracy = "The Illuminati is a secret society that controls the world.";
            break;
        case 3:
            conspiracy = "9/11 was an inside job.";
            break;
        case 4:
            conspiracy = "The earth is flat and NASA is lying to us.";
            break;
        default:
            printf("Error: Invalid conspiracy theory chosen. Exiting program...\n");
            return 1;
    }

    printf("Conspiracy theory: %s\n", conspiracy);

    return 0;
}