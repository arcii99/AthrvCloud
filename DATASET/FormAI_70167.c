//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    char *nouns[10] = {"government", "aliens", "illuminati", "big pharma", "Masons", "New World Order", "bankers", "CIA", "FBI", "NSA"};
    char *verbs[10] = {"covering up", "controlling", "manipulating", "hiding", "brainwashing", "experimenting on", "enslaving", "spying on", "infiltrating", "silencing"};
    char *adjectives[10] = {"secret", "hidden", "classified", "suppressed", "mysterious", "unseen", "covert", "esoteric", "veiled", "obscurantist"};
    char *conspiracy[10] = {"9/11", "moon landing", "JFK assassination", "COVID-19", "global warming", "vaccines", "chemtrails", "flat earth", "CERN", "Area 51"};

    printf("Welcome to Random Conspiracy Theory Generator!\n");
    printf("------------------------------------------\n\n");

    char ans;
    do {
        int n1 = rand() % 10; // random index for noun
        int v1 = rand() % 10; // random index for verb
        int a1 = rand() % 10; // random index for adjective
        int c1 = rand() % 10; // random index for conspiracy

        printf("Did you know that the %s are %s the %s of the %s?\n", adjectives[a1], verbs[v1], nouns[n1], conspiracy[c1]);
        printf("It's true! The evidence is all around us, if only people would open their eyes...\n\n");

        printf("Do you want to hear another conspiracy theory? (y/n): ");
        scanf(" %c", &ans);
        printf("\n");
    } while (ans == 'y');

    printf("Thanks for using Random Conspiracy Theory Generator!\n");
    return 0;
}