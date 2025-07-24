//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the C Random Conspiracy Theory Generator!\n");

    // Seed random number generator
    srand(time(NULL));

    // Conspiracy theories array
    char* theories[10] = {
        "The moon landing was faked",
        "Aliens are among us",
        "The government is hiding the cure for cancer",
        "The Earth is flat",
        "Birds aren't real",
        "The Illuminati controls everything",
        "The Titanic was sunk intentionally",
        "The Mandela Effect is evidence of parallel universes",
        "9/11 was an inside job",
        "The Loch Ness Monster is real"
    };

    // Randomly generate conspiracy theory
    int random_index = rand() % 10;
    char* theory = theories[random_index];

    // Display conspiracy theory
    printf("Conspiracy theory: %s\n", theory);

    // Cheesy closing message
    printf("Thanks for playing! Don't forget to wear your tin foil hat!\n");

    return 0;
}