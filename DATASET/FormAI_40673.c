//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // get user input for probability of an alien invasion
    float probability;
    printf("Please enter the probability (as a percentage) of an alien invasion: ");
    scanf("%f", &probability);

    // calculate likelihood of an invasion and output result
    float likelihood = probability / 100;
    printf("\nThere is a %f chance of an alien invasion.\n\n", likelihood);

    // generate a random number between 0 and 1 to determine if invasion occurs
    float random_num = (float) rand() / (float) RAND_MAX;

    // determine if invasion occurs based on random number and likelihood
    if (random_num <= likelihood) {
        printf("ALIEN INVASION DETECTED!!! TAKE COVER!!!\n");
    } else {
        printf("No alien invasion detected. Carry on with your day.\n");
    }

    return 0;
}