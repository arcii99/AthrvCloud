//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array of conspiracy theories
char *conspiracy_theories[] = {
    "The moon landing was faked",
    "The government is hiding evidence of alien life",
    "9/11 was an inside job",
    "Chemtrails are being sprayed to control the population",
    "The Illuminati controls the world",
    "Vaccines cause autism",
    "Flat Earth theory is true"
};

// Random number generator
int random_number(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main() {
    // Print a random conspiracy theory
    printf("Did you know that %s?\n", conspiracy_theories[random_number(0, 6)]);
    
    return 0;
}