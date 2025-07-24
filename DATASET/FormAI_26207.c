//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float prob;
    int rand_num;

    srand(time(NULL)); //Set the random number generator seed to the current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the probability of an alien invasion as a decimal between 0 and 1: ");
    scanf("%f", &prob);

    if(prob >= 0 && prob <= 1) {
        rand_num = rand() % 100 + 1; //Generate a random number between 1 and 100
        printf("Generating random number...\n");
        printf("The aliens have a %f%% chance of invading.\n", prob*100);

        if(rand_num > prob*100) { //Compare the random number to the probability
            printf("Congratulations, you have avoided an alien invasion!\n");
        } else {
            printf("WARNING: Aliens detected! Please take immediate action to protect yourself.\n");
        }
    } else {
        printf("Invalid input. Please enter a decimal between 0 and 1.\n");
    }

    return 0;
}