//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generateRandomConspiracyTheory() {
    // Generate a random conspiracy theory
    char* theories[] = {
        "The moon landing was faked by the government.",
        "The Illuminati control the world's governments.",
        "Aliens have already made contact with Earth.",
        "The government is hiding the cure for cancer.",
        "Chemtrails are secretly being used to control the population.",
        "9/11 was orchestrated by the government.",
        "The CIA is responsible for JFK's assassination.",
        "The Earth is flat and the government is hiding the truth.",
        "The government has a secret time travel program.",
        "The royal family are actually reptilian aliens.",
        "The government is using mind control to create a New World Order."
    };
    
    int numTheories = sizeof(theories) / sizeof(char*);
    int randIndex = rand() % numTheories;
    
    return theories[randIndex];
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random conspiracy theory
    char* theory = generateRandomConspiracyTheory();
    
    // Output the conspiracy theory
    printf("Did you know that %s?\n", theory);
    
    // Generate another theory
    theory = generateRandomConspiracyTheory();
    printf("Also, apparently %s!\n", theory);
    
    return 0;
}