//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    int length = 10;
    int numbers[length];
    int i;

    // Fill array with random numbers between 1 and 100
    for (i = 0; i < length; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    // Print original array
    printf("Original array: ");
    for (i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Sort array in ascending order
    int j, temp;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}