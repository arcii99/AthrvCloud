//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>

#define ARRAY_SIZE 10000000

int main() {
    int i;
    int array[ARRAY_SIZE];

    // Initialize the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Calculate the sum of the array elements
    int sum = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }

    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}