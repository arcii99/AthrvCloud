//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator
    srand(time(NULL));

    // define conspiracy theories
    char *conspiracy_theories[] = {
        "The moon landing was faked",
        "9/11 was an inside job",
        "The government is hiding evidence of alien life",
        "COVID-19 was artificially created in a lab",
        "Chemtrails are being used to control the population",
        "The earth is flat",
        "The Illuminati controls the world",
        "The CIA assassinated JFK",
        "The New World Order is coming",
        "Reptilian aliens are controlling world leaders"
    };

    // generate a random conspiracy theory
    int random_index = rand() % 10;
    char *conspiracy_theory = conspiracy_theories[random_index];

    // print the conspiracy theory
    printf("Did you know... %s?\n", conspiracy_theory);

    return 0;
}