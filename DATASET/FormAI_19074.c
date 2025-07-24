//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void printBucketSort(int nums[], int n, int max_value) {
    int bucket[max_value+1];
    
    for (int i = 0; i <= max_value; i++) {
        bucket[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        bucket[nums[i]]++;
    }
    
    for (int i = 0, j = 0; j <= max_value; j++) {
        for (int k = bucket[j]; k > 0; k--) {
            nums[i++] = j;
        }
    }
    
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main() {
    int n, max_value;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (i == 0)
            max_value = nums[i];
        else if (nums[i] > max_value)
            max_value = nums[i];
    }
    
    printf("Original array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
        
    printBucketSort(nums, n, max_value);
    
    return 0;
}