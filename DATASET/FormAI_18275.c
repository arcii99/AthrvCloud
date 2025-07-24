//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    int aliens = 0;
    int years = 0;

    // Happy greetings
    printf("Welcome to the Alien Invasion Probability Calculator! :)\n");
    printf("Let's see if aliens will invade your planet within the next 100 years!\n");

    // Let's get the number of aliens that could invade
    printf("How many aliens do you think are out there? (enter a number)\n");
    scanf("%d", &aliens);

    // Let's calculate the probability of an invasion each year
    float probability = (float)aliens / 1000000;
    printf("The probability of an alien invasion each year is %.5f%%.\n", probability * 100);

    // Let's calculate the probability of an invasion in the next 100 years
    float invasionProb = 1 - pow(1 - probability, 100);
    printf("The probability of an alien invasion in the next 100 years is %.5f%%.\n", invasionProb * 100);

    // Let's determine how long before an invasion is likely
    while (invasionProb < 50) {
        years++;
        invasionProb = 1 - pow(1 - probability, years + 100);
    }

    // Let's print the results and a happy message
    printf("Based on the number of aliens you entered, there is a high chance that an alien invasion will occur within the next %d years!\n", years);
    printf("Stay happy and be prepared just in case! :D\n");

    return 0;
}