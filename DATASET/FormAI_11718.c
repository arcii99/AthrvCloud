//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program will generate 10 random numbers between 1-50, and output them to the console. */

int main() {
    // Setting up the seed for the random number generator
    srand(time(0));
    printf("Generating 10 Random Numbers between 1-50:\n");
    for (int i = 0; i < 10; i++) {
        int random_number = rand() % 50 + 1;
        printf("%d ", random_number);
    }
    printf("\n");
    return 0;
}