//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionProbability;

    // Seed for random number generation
    srand(time(NULL));

    // Generate a random number as invasion probability
    invasionProbability = rand() % 101;

    // Print the invasion probability
    printf("The probability of alien invasion is: %d%%\n", invasionProbability);

    // Check if invasion probability is high and suggest actions
    if (invasionProbability >= 75) {
        printf("The invasion probability is very high!\n");
        printf("Please take the following actions to protect yourself:\n");
        printf("- Stay indoors and avoid going outside.\n");
        printf("- Stock up on supplies like food and water.\n");
        printf("- Prepare a safe room in your house.\n");
        printf("- Tune in to emergency broadcast stations for updates.\n");
    } else if (invasionProbability >= 50 && invasionProbability < 75) {
        printf("The invasion probability is moderate.\n");
        printf("Please take the following actions to prepare for any contingency:\n");
        printf("- Keep emergency supplies ready.\n");
        printf("- Keep important documents and IDs in one place.\n");
        printf("- Stay vigilant and keep an eye on the news.\n");
    } else {
        printf("The invasion probability is low.\n");
        printf("While the probability may be low, it's always better to be prepared.\n");
        printf("Please take the following actions to prepare for any contingency:\n");
        printf("- Keep emergency supplies ready.\n");
        printf("- Keep important documents and IDs in one place.\n");
        printf("- Stay vigilant and keep an eye on the news.\n");
    }

    return 0;
}