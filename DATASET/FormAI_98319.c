//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation

    char* conspiracy[] = {
        "The moon landing was faked",
        "9/11 was an inside job",
        "The Illuminati controls world governments",
        "Aliens are among us",
        "The world is run by lizard people",
        "Chemtrails are being used for mind control",
        "The Earth is flat",
        "The government is hiding evidence of extraterrestrial life"
    };

    int num_conspiracies = sizeof(conspiracy) / sizeof(conspiracy[0]); // Number of conspiracy theories

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    printf("Generating random conspiracy theory...\n\n");

    int rand_index = rand() % num_conspiracies; // Choose a random conspiracy theory

    printf("Conspiracy Theory: %s\n", conspiracy[rand_index]); // Print the chosen conspiracy theory

    return 0;
}