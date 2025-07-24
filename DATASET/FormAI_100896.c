//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 1000000

int main() {

    int nums[MAX_NUMS];
    int sum = 0;

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMS; i++) {
        nums[i] = rand() % 1000;
    }

    // Benchmarking starts
    clock_t start = clock();

    for (int i = 0; i < MAX_NUMS; i++) {
        sum += nums[i];
    }

    // Benchmarking ends     
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sum of %d numbers is %d\n", MAX_NUMS, sum);
    printf("Time taken: %lf seconds\n", time_spent);

    return 0;
}