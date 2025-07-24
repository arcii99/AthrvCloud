//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed based on current time
    srand(time(NULL));

    // Define arrays of possible conspiracy theories and suspects
    char *conspiracies[] = {
        "The Moon landing was faked by the government",
        "Chemtrails are being used to control the population",
        "CERN created a black hole that will destroy the world",
        "The Illuminati controls all major governments",
        "9/11 was an inside job by the government"
    };
    char *suspects[] = {
        "The government",
        "Big Pharma",
        "The Illuminati",
        "Aliens",
        "Time travelers"
    };

    // Choose a random conspiracy theory and suspect
    int conspiracyIndex = rand() % 5;
    int suspectIndex = rand() % 5;

    // Print the conspiracy theory and suspect
    printf("Did you know that %s is actually a plot by %s?\n", conspiracies[conspiracyIndex], suspects[suspectIndex]);

    // Generate a random level of belief in the conspiracy
    int beliefLevel = rand() % 101;

    // Print the level of belief in the conspiracy
    if (beliefLevel > 90) {
        printf("It's completely true! Wake up, sheeple!\n");
    } else if (beliefLevel > 70) {
        printf("There's definitely something fishy going on...\n");
    } else if (beliefLevel > 50) {
        printf("It's hard to say, but there might be some truth to it.\n");
    } else {
        printf("It's probably just a bunch of nonsense.\n");
    }
    
    return 0;
}