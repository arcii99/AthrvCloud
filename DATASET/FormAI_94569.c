//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main() {

    int i;
    int numbers[ARRAY_SIZE];
    int min_number = 0;
    int max_number = 100;

    srand(time(NULL));

    // Fill array with random numbers between min_number and max_number
    for (i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = (rand() % (max_number - min_number + 1)) + min_number;
    }

    // Print array
    printf("Random numbers between %d and %d:\n", min_number, max_number);
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", numbers[i]);
    }

    // Calculate sum and average of numbers
    int sum = 0;
    double average;
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += numbers[i];
    }
    average = (double)sum / ARRAY_SIZE;

    // Print sum and average
    printf("\n\nSum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", average);

    return 0;
}