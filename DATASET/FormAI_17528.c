//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

int main() {
    int *p[MAX_ITEMS], i, j;

    // allocate 1000 blocks of memory of random sizes between 1 and 100
    for (i = 0; i < MAX_ITEMS; i++) {
        int size = rand() % 100 + 1;
        p[i] = (int*)malloc(size * sizeof(int));
        if (p[i] == NULL) {
            // if malloc fails, print error message and exit
            printf("Error: Unable to allocate memory\n");
            for (j = 0; j < i; j++) {
                free(p[j]);
            }
            return 1;
        }
        // initialize values to ascending sequence
        for (j = 0; j < size; j++) {
            p[i][j] = j;
        }
    }

    // free every other block of memory
    for (i = 0; i < MAX_ITEMS; i += 2) {
        free(p[i]);
        p[i] = NULL;
    }

    // allocate 100 new blocks of memory of random sizes between 1 and 100
    for (i = 0; i < 100; i++) {
        int size = rand() % 100 + 1;
        p[i] = (int*)malloc(size * sizeof(int));
        if (p[i] == NULL) {
            // if malloc fails, print error message and exit
            printf("Error: Unable to allocate memory\n");
            for (j = 0; j < MAX_ITEMS; j++) {
                if (p[j] != NULL) {
                    free(p[j]);
                }
            }
            return 1;
        }
        // initialize values to descending sequence
        for (j = 0; j < size; j++) {
            p[i][j] = size - j - 1;
        }
    }

    // print out the sum of the first 10 values in every allocated block of memory
    long long sum = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (p[i] != NULL) {
            for (j = 0; j < 10 && j < sizeof(p[i]) / sizeof(int); j++) {
                sum += p[i][j];
            }
        }
    }
    printf("Sum of first 10 values in all allocated blocks: %lld\n", sum);

    // free all remaining allocated memory
    for (i = 0; i < MAX_ITEMS; i++) {
        if (p[i] != NULL) {
            free(p[i]);
        }
    }

    return 0;
}