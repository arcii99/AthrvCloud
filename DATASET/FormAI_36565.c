//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

int main() {
    int nums[] = {34, 6, 19, 42, 12, 5};
    int n = sizeof(nums)/sizeof(nums[0]);
    int i, j, temp;

    // Display original array
    printf("Original Array: ");
    for(i=0; i<n; i++) {
        printf("%d ", nums[i]);
    }

    // Sorting Algorithm
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    // Display sorted array
    printf("\nSorted Array: ");
    for(i=0; i<n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}