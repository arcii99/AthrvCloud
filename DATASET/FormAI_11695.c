//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // seeding the rng with the current time
    int probability = rand() % 101; // generating a random number between 0 and 100
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Calculating the probability of an alien invasion...\n");
    printf("Probability: %d%%\n", probability);

    if (probability <= 5) {
        printf("\nAlien invasion is highly unlikely. You have nothing to worry about!\n");
    } else if (probability > 5 && probability <= 25) {
        printf("\nAlien invasion is possible, but it is not very likely to happen anytime soon.\n");
        printf("However, it is always better to be prepared for the worst.\n");
    } else if (probability > 25 && probability <= 75) {
        printf("\nAlien invasion is likely to occur in the near future.\n");
        printf("Please take necessary precautions and stay informed about developing news.\n");
    } else {
        printf("\nAlien invasion is very likely to occur. Please seek shelter immediately!\n");
        printf("Refer to emergency procedures and remain calm.\n");
    }

    return 0;
}