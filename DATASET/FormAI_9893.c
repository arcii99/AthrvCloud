//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    // List of conspiracy theories
    const char *theories[] = {
        "The moon landing was fake.",
        "Chemtrails are being used to control the population.",
        "The government is hiding evidence of extraterrestrial life.",
        "The Illuminati control the world.",
        "Global warming is a hoax created by hippies.",
        "The earth is flat.",
        "9/11 was an inside job.",
        "The New World Order is coming.",
        "The Bermuda Triangle is cursed.",
        "The Denver airport is a secret headquarters for the elite."
    };

    // Generate a random conspiracy theory
    int index = rand() % 10; // choose a random index from the array
    printf("Conspiracy theory: %s\n", theories[index]);

    return 0;
}