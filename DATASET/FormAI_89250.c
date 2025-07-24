//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between two numbers
int generateRandomInt(int min, int max) {
    int randNum = rand() % (max - min + 1) + min;
    return randNum;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Arrays of conspiracy theories and possible culprits
    char *theories[] = {
        "The moon landing was faked by the government.",
        "The earth is flat and NASA is lying to us.",
        "911 was an inside job.",
        "Chemtrails are being used to control the population.",
        "The Illuminati is controlling world governments.",
        "Vaccines are causing autism.",
        "The government is covering up the existence of aliens."
    };

    char *culprits[] = {
        "The government",
        "The Illuminati",
        "The New World Order",
        "The Bilderberg Group",
        "The Rothschilds",
        "The Freemasons",
        "The Reptilian overlords"
    };

    // Generate a random conspiracy theory and culprit
    int theoryIndex = generateRandomInt(0, sizeof(theories) / sizeof(char*) - 1);
    int culpritIndex = generateRandomInt(0, sizeof(culprits) / sizeof(char*) - 1);
    char *theory = theories[theoryIndex];
    char *culprit = culprits[culpritIndex];

    // Print the conspiracy theory
    printf("Random Conspiracy Theory Generator:\n\n");
    printf("%s\n", theory);
    printf("\n");

    // Print the culprit and their motive
    printf("Possible Culprit: %s\n", culprit);
    printf("Motive: ");

    // The motive is different for each conspiracy theory
    switch(theoryIndex) {
        case 0: printf("To win the Space Race and gain power over the Soviet Union.\n"); break;
        case 1: printf("To hide the truth from the masses and keep them under control.\n"); break;
        case 2: printf("To justify going to war in the Middle East and gaining power over oil resources.\n"); break;
        case 3: printf("To weaken and control the population, making them easier to govern.\n"); break;
        case 4: printf("To create a New World Order and rule the world from the shadows.\n"); break;
        case 5: printf("To depopulate the world and take away our freedom of choice.\n"); break;
        case 6: printf("To prevent panic and maintain power over the population.\n"); break;
        default: printf("Unknown\n"); break;
    }
   
    return 0;
}