//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* theories[] = { // List of conspiracy theories
    "The moon landing was fake.",
    "The earth is flat.",
    "The government is hiding the existence of aliens.",
    "9/11 was an inside job.",
    "The Illuminati controls the world.",
    "The Bermuda Triangle is a portal to another dimension.",
    "The world will end on December 21, 2012.",
    "Chemtrails are being used to control the population.",
    "The rich and powerful are part of a secret society called the Bilderberg Group.",
    "The Denver airport is a secret government base.",
    "The Mayan calendar predicted a coming cataclysmic event.",
    "The Illuminati is hiding the cure for cancer.",
    "The government is controlling our minds with radio waves.",
    "The FBI killed Martin Luther King Jr.",
    "The Vatican is hiding evidence of extraterrestrial life.",
};

char* random_theory() { // Function to select a random theory
    srand(time(NULL)); // Seed the random number generator with the current time
    int index = rand() % (sizeof(theories) / sizeof(theories[0])); // Get a random index for the theories array
    return theories[index]; // Return a random theory
}

void main() {
    printf("%s\n", random_theory()); // Print a random conspiracy theory
}