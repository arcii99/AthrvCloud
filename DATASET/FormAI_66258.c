//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CYCLES 1000000000

int main(int argc, char *argv[]) {
    int i, cycles = MAX_CYCLES;
    if (argc > 1) cycles = atoi(argv[1]);

    clock_t start = clock();

    for (i = 0; i < cycles; i++) {
        // Perform a time critical operation here
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        } else {
            printf("Odd: %d\n", i);
        }
    }
    
    clock_t end = clock();
    double time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time elapsed: %f seconds\n", time_elapsed);

    return 0;
}