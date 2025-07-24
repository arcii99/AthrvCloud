//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char* nouns[] = {"government", "aliens", "Illuminati", "big pharma", "Masons", "reptilians", "CIA", "Freemasons", "NASA", "New World Order"};
    char* adjectives[] = {"secret", "hidden", "malevolent", "powerful", "sinister", "unknown", "ominous", "shadowy", "covert", "conspiratorial"};

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    while (1) { // Keep generating conspiracy theories indefinitely
        printf("Did you know that the %s is %s?\n\n", nouns[rand() % 10], adjectives[rand() % 10]);

        char response[10];
        printf("Would you like to hear another conspiracy theory? (y/n): ");
        scanf("%s", response);

        if (tolower(response[0]) == 'n') { // If the user doesn't want to hear another conspiracy theory, exit the program
            break;
        }
    }

    printf("\nThanks for using the Random Conspiracy Theory Generator! Remember to always question everything...\n");

    return 0;
}