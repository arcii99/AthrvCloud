//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    while(1) {
        // Seed the random number generator
        srand(time(NULL));

        // Generate random integers for various parts of the conspiracy theory
        int numAdjectives = rand() % 5 + 1;
        int numNouns = rand() % 5 + 1;

        // Arrays of possible adjectives and nouns
        char *adjectives[] = {"government", "corporate", "alien", "Illuminati", "military"};
        char *nouns[] = {"mind control", "weather modification", "vaccines", "chemtrails", "cryptocurrency"};

        printf("Did you know that the %s is using %s for %s?\n", adjectives[numAdjectives], nouns[numNouns], nouns[rand() % 5]);

        printf("Hit enter to generate another conspiracy theory, or Q to quit: ");
        char input = getchar();
        if(input == 'Q' || input == 'q') {
            printf("Exiting program...\n");
            break;
        }
    }

    return 0;
}