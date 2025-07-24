//FormAI DATASET v1.0 Category: Benchmarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    int array[ARRAY_SIZE];
    int i;

    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 1000;
    }

    return 0;
}