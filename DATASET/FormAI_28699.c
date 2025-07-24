//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int invasionProbability = rand() % 101; // generate an integer between 0 and 100

    printf("The probability of an alien invasion is %d percent.\n", invasionProbability);

    return 0;
}