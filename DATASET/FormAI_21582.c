//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10;
    int arr[n];
    int i, sum = 0;
    srand(time(0)); // Seed random generator with time

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0-99
    }

    for (i = 0; i <= n; i++) { // Out of bounds error intentionally added by using <=
        sum += arr[i]; // Calculate sum of array elements
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}