//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int invasionProb = rand() % 101; // generate a random number between 0 and 100
    printf("Welcome to the Alien Invasion Probability Calculator 3000!\n\n");
    printf("The chance of an alien invasion is currently estimated to be %d%%.", invasionProb);
    if (invasionProb >= 80) {
        printf(" WARNING: This is an extremely high probability of invasion. Take all necessary precautions.\n");
    } else if (invasionProb >= 50) {
        printf(" It is recommended that you prepare for the possibility of an invasion.\n");
    } else {
        printf(" The chance of an invasion is relatively low at this time, but it's never a bad idea to be prepared.\n");
    }
    printf("\nKeep monitoring the probability and stay safe out there!\n");
    return 0;
}