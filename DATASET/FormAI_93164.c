//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {

    int *arr = (int *)malloc(sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    // Perform a simple calculation on each element of the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = arr[i] * 2;
    }

    int sum = 0;
    // Calculate the sum of all elements in the array
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    printf("The sum is: %d\n", sum);

    free(arr);

    return 0;
}