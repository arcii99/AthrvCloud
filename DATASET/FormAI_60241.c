//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VALUES 1000000

int main() {
    int values[NUM_VALUES];
    int i, j, temp;

    // Fill array with random integers
    srand(time(NULL));
    for (i = 0; i < NUM_VALUES; i++) {
        values[i] = rand();
    }

    // Perform insertion sort
    for (i = 1; i < NUM_VALUES; i++) {
        j = i;
        while (j > 0 && values[j] < values[j-1]) {
            // Swap values[j] and values[j-1]
            temp = values[j];
            values[j] = values[j-1];
            values[j-1] = temp;
            j--;
        }
    }

    // Print sorted array
    for (i = 0; i < NUM_VALUES; i++) {
        printf("%d\n", values[i]);
    }

    return 0;
}