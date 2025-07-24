//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Define the conspiracy theories
    char *conspiracyTheories[] = {
        "The moon landing was faked by the government.",
        "The Illuminati is controlling the world.",
        "The government is hiding evidence of extraterrestrial life.",
        "9/11 was an inside job.",
        "The pharmaceutical industry is suppressing cures for diseases.",
        "Climate change is a hoax created by the government.",
        "The Denver airport is hiding a secret underground bunker.",
        "The pyramids were built by aliens.",
        "Bigfoot is real and the government is covering it up.",
        "The Earth is flat and the government is lying about it."
    };

    // Generate a random conspiracy theory
    int randomIndex = rand() % 10;
    char *randomTheory = conspiracyTheories[randomIndex];

    // Print the conspiracy theory
    printf("Did you know? %s\n", randomTheory);

    return 0;
}