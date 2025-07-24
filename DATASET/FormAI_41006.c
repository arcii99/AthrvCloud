//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main() {
    int i, randomNumber;
    int randomNumbers[ARRAY_SIZE] = {0};

    // Initialize random number generator with current time
    srand((unsigned int)time(NULL));

    // Generate 10 random numbers between 1 and 100
    printf("Generating 10 random numbers between 1 and 100:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        randomNumber = rand() % 100 + 1;
        printf("%d ", randomNumber);
        randomNumbers[i] = randomNumber;
    }

    // Find the smallest and largest number in the array
    int smallest = randomNumbers[0], largest = randomNumbers[0];
    for (i = 1; i < ARRAY_SIZE; i++) {
        if (randomNumbers[i] < smallest) {
            smallest = randomNumbers[i];
        }
        if (randomNumbers[i] > largest) {
            largest = randomNumbers[i];
        }
    }

    printf("\n\nThe smallest number is %d", smallest);
    printf("\nThe largest number is %d", largest);

    return 0;
}