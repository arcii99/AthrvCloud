//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array of conspiracy theories
char *conspiracies[] = {
    "The moon landing was faked.",
    "The government is hiding information about aliens.",
    "The Illuminati controls the world.",
    "The JFK assassination was a government plot.",
    "The Earth is flat.",
    "9/11 was an inside job.",
    "The vaccine industry is a cover up for population control.",
    "The New World Order is coming.",
    "Elvis faked his own death.",
    "The Denver Airport is a secret government facility."
};

// Function to generate a random number within a range
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate a random conspiracy theory
    int index = randRange(0, 9);
    char *conspiracy = conspiracies[index];

    // Print out the conspiracy theory
    printf("Did you know that %s?\n", conspiracy);

    return 0;
}