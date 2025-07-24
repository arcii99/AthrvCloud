//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Allocate space for an array of size 10 integers
    int* nums = (int*)malloc(10 * sizeof(int));
    
    if(nums == NULL) {
        printf("Could not allocate memory");
        return 0;
    }
    
    // Initialize array with ascending values
    for(int i=0; i<10; i++) {
        nums[i] = i;
    }
    
    // Print array values
    printf("Array values: ");
    for(int i=0; i<10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    // Resize array in memory
    nums = (int*)realloc(nums, 15 * sizeof(int));
    
    if(nums == NULL) {
        printf("Could not reallocate memory");
        return 0;
    }
    
    // Initialize new values in the array
    for(int i=10; i<15; i++) {
        nums[i] = i;
    }
    
    // Print updated array values
    printf("Updated array values: ");
    for(int i=0; i<15; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(nums);
    
    return 0;
}