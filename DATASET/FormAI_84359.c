//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two given integers
int generateRandomNumber(int min, int max) {
    int randomNum = (rand() % (max - min + 1)) + min;
    return randomNum;
}

// Function to generate a random conspiracy theory
void generateConspiracyTheory() {
    // Define the various elements of the conspiracy theory
    char *nouns[] = {"aliens", "government", "Illuminati", "Big Pharma", "deep state", "Freemasons"};
    char *adjectives[] = {"secret", "hidden", "covert", "manipulative", "sinister", "deceptive"};
    char *actions[] = {"control", "manipulate", "brainwash", "dominate", "subvert", "enslave"};
    char *targets[] = {"humanity", "the world", "the economy", "the media", "the environment", "the election"};

    // Define the length of each array
    int numNouns = sizeof(nouns) / sizeof(nouns[0]);
    int numAdjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    int numActions = sizeof(actions) / sizeof(actions[0]);
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    // Generate a random conspiracy theory by selecting one element from each array
    int nounIndex = generateRandomNumber(0, numNouns - 1);
    int adjectiveIndex = generateRandomNumber(0, numAdjectives - 1);
    int actionIndex = generateRandomNumber(0, numActions - 1);
    int targetIndex = generateRandomNumber(0, numTargets - 1);

    // Output the generated conspiracy theory
    printf("Did you know that %s, the %s %s, is trying to %s %s?\n", nouns[nounIndex], adjectives[adjectiveIndex], nouns[nounIndex], actions[actionIndex], targets[targetIndex]);
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    // Generate and output 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        generateConspiracyTheory();
        printf("\n");
    }
    
    return 0;
}