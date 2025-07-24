//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100000000 // increased MAX_SIZE to 100000000

// This program generates random numbers and calculates their sum
int main() {
    int *arr = malloc(MAX_SIZE * sizeof(int)); // allocate memory for array dynamically 
    if (arr == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(1);
    }

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate the sum of the array
    int sum = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }

    printf("The sum is: %d\n", sum);

    free(arr); // free allocated memory

    return 0;
}