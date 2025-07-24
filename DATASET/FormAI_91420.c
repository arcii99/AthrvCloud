//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i, r;
    printf("Welcome to the random number generator!\n");
    printf("How many numbers would you like to generate? ");
    scanf("%d", &i);
    printf("Generating %d random numbers...\n", i);
    for(int j = 0; j < i; j++) {
        r = rand() % 100;
        printf("Random number %d: %d\n", j+1, r);
    }
    printf("Done generating random numbers.\n");
    return 0;
}