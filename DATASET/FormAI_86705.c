//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int humanPop, alienProb;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the total human population of the planet:\n");
    scanf("%d", &humanPop);

    printf("\nCalculating probability of alien invasion...\n");

    for(int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    printf("\n\nAlien invasion probability has been calculated!\n");

    alienProb = rand() % 101;

    if(alienProb >= 40) {
        printf("Oh no! The probability of an alien invasion is %d%%. This is not good news.\n", alienProb);
    }
    else if(alienProb >= 20) {
        printf("The probability of an alien invasion is %d%%. It's not a high chance, but better safe than sorry!\n", alienProb);
    }
    else {
        printf("Phew! The probability of an alien invasion is only %d%%. We can all rest easy!\n", alienProb);
    }

    return 0;
}