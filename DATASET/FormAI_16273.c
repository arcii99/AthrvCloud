//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Initializing the random seed

    float alienProb = ((float)rand() / RAND_MAX) * 100;  // Generating a random number between 0 and 100 for the probability of an alien invasion

    printf("The probability of an alien invasion is: %.2f%%", alienProb);  // Printing the probability with 2 decimal places and a % symbol
    
    return 0;
}