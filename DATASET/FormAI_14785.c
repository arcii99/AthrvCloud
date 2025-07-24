//FormAI DATASET v1.0 Category: Random ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Generate 50 random numbers
    int i, random_num;
    for (i = 1; i <= 50; i++) {
        random_num = rand() % 100; // Generate a random number between 0 and 99
        printf("Random Number %d: %d\n", i, random_num);
    }

    return 0;
}