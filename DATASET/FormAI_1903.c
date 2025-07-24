//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nums[10];
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 random numbers between 1 and 100
    for (i = 0; i < 10; i++) {
        nums[i] = rand() % 100 + 1;
    }

    // Print the random numbers
    printf("Random numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Sort the numbers using bubble sort
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (nums[j] > nums[j+1]) {
                // Swap the two numbers
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    // Print the sorted numbers
    printf("Sorted numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}