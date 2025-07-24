//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, randomNumber;
    srand(time(0)); // seed the random number generator

    // Generate 10 random numbers between 1 and 100
    for(i=0; i<10; i++) {
        randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100
        printf("Random Number %d: %d\n", i+1, randomNumber);
    }

    return 0;
}