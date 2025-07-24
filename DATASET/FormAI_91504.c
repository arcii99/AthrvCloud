//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This C program generates random numbers using built-in library functions.

int main() {
    int i, n;
    printf("How many random numbers do you want to generate?\n");
    scanf("%d", &n);
    printf("Generating %d random numbers...\n\n", n);

    // To generate truly random numbers, we need to seed the random number generator with the current time
    srand(time(NULL));

    for (i = 1; i <= n; i++) {
        int random_number = rand(); // generate a random number between 0 and RAND_MAX
        printf("%d\n", random_number);
    }

    printf("\nDone!");
    return 0;
}