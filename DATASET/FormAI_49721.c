//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char response[10];
    srand(time(0)); // set seed for random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Do you think aliens will invade Earth soon? (Y/N): ");
    scanf("%s", &response);

    if (response[0] == 'Y' || response[0] == 'y') {
        printf("Interesting! Let's see if your prediction is correct.\n");
        printf("Calculating...\n");
        int probability = rand() % 101; // generate random number between 0 and 100

        // print message depending on probability
        if (probability >= 0 && probability <= 25) {
            printf("You're safe for now. The probability of an alien invasion is only %d%%.\n", probability);
        } else if (probability >= 26 && probability <= 50) {
            printf("Be on guard, the probability of an alien invasion is %d%%.\n", probability);
        } else if (probability >= 51 && probability <= 75) {
            printf("It's looking grim, the probability of an alien invasion is %d%%.\n", probability);
        } else {
            printf("Oh no! The probability of an alien invasion is %d%%. Prepare for the worst.\n", probability);
        }
    } else if (response[0] == 'N' || response[0] == 'n') {
        printf("Well, that's a relief! Let's hope it stays that way.\n");
    } else {
        printf("Sorry, I didn't understand your response.\n");
    }

    return 0;
}