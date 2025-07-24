//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator with current time
    int invasionProb = rand() % 101; // generate a random invasion probability from 0 to 100
    printf("Alien Invasion Probability: %d%\n", invasionProb);
    if (invasionProb >= 80) {
        printf("The probability of an alien invasion is very high.\n");
    } else if (invasionProb >= 60) {
        printf("The probability of an alien invasion is moderate.\n");
    } else if (invasionProb >= 40) {
        printf("The probability of an alien invasion is low.\n");
    } else {
        printf("The probability of an alien invasion is very low.\n");
    }
    return 0;
}