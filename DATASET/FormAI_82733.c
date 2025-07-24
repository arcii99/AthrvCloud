//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialise random number generator

    int x = rand() % 101; // Generate a random number between 0 and 100
    int y = rand() % 101;
    int z = rand() % 101;

    printf("What is the product of %d, %d, and %d?\n", x, y, z);

    int answer;
    scanf("%d", &answer);

    int result = x * y * z;

    if (answer == result) {
        printf("Correct! The answer is %d.\n", result);
    } else {
        printf("Sorry, that's incorrect. The answer is %d.\n", result);
    }

    return 0;
}