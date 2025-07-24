//FormAI DATASET v1.0 Category: Digital signal processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int buffer[BUFFER_SIZE];
    int i, j, k;

    // Initialize buffer with random values
    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = rand();
    }

    // Apply signal processing algorithm
    for (i = 0; i < BUFFER_SIZE; i++) {
        int sum = 0;
        int count = 0;
        for (j = -10; j <= 10; j++) {
            k = i + j;
            if (k >= 0 && k < BUFFER_SIZE) {
                sum += buffer[k];
                count++;
            }
        }
        buffer[i] = sum / count;
    }

    // Print result
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}