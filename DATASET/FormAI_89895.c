//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // Seed for the random number generator

    char question[100];

    printf("Welcome to the automated fortune teller! Please ask a yes or no question: ");
    fgets(question, 100, stdin); // Get user input

    int answer = rand() % 2; // Generate a random number between 0 and 1

    if (answer == 0) {
        printf("The answer is no. ");
    } else {
        printf("The answer is yes. ");
    }

    // Generate a random message of inspiration or caution
    int message = rand() % 4;
    switch(message) {
        case 0:
            printf("But remember: every obstacle is an opportunity in disguise.");
            break;
        case 1:
            printf("Just be careful not to get in over your head.");
            break;
        case 2:
            printf("Keep focused on your goals and you will achieve them.");
            break;
        case 3:
            printf("Be open to new experiences and you will be rewarded.");
            break;
    }

    return 0;
}