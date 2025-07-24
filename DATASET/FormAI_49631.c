//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int numbers[ARRAY_SIZE];
    int sum = 0;
    int i;

    // Generate random numbers and store them in array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 100;
    }

    // Calculate the sum of all numbers in the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += numbers[i];
    }

    printf("The sum of all numbers in the array is %d\n", sum);

    return 0;
}