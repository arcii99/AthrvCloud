//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_elements;
    int* nums;

    printf("How many elements do you want to store? ");
    scanf("%d", &num_elements);

    // Allocate memory
    nums = (int*) malloc(num_elements * sizeof(int));

    if (nums == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Fill array with user input
    printf("Enter your elements: ");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &nums[i]);
    }

    // Print array
    printf("Your array: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", nums[i]);
    }

    // Deallocate memory
    free(nums);

    return 0;
}