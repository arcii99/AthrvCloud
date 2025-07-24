//FormAI DATASET v1.0 Category: Random ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int random_number = rand() % 100 + 1;

    // Print out the random number to the user
    printf("Your random number is: %d\n", random_number);

    return 0;
}