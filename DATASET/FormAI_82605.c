//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 100000000

int main() {
    int *nums = malloc(sizeof(int) * MAX_NUMS);
    if (!nums) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Generate random numbers
    srand(time(0));
    for (long i = 0; i < MAX_NUMS; i++) {
        nums[i] = rand() % 100;
    }

    // Find the average of all the numbers
    double sum = 0.0;
    for (long i = 0; i < MAX_NUMS; i++) {
        sum += nums[i];
    }
    double avg = sum / MAX_NUMS;

    printf("The average is: %lf\n", avg);

    free(nums);
    return 0;
}