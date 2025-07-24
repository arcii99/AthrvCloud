//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
/* Here's a creative interpretation of a binary search algorithm, 
inspired by the works of information theorist Claude Shannon */

#include <stdio.h>

#define MAX_SIZE 10

void shannon_search(int arr[], int low, int high, int target) {
    if (high < low) {
        printf("Target not found in array.\n");
        return;
    }
    
    int mid = (low + high) / 2;
    
    if (arr[mid] == target) {
        printf("Target %d found at index %d\n", target, mid);
        return;
    }
    else if (arr[mid] > target) {
        printf("Searching left half of array from index %d to index %d\n", low, mid-1);
        shannon_search(arr, low, mid-1, target);
    }
    else {
        printf("Searching right half of array from index %d to index %d\n", mid+1, high);
        shannon_search(arr, mid+1, high, target);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;
    
    printf("Enter the size of the array (must not exceed %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    printf("\nEnter the elements of the array one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the target element to search for: ");
    int target;
    scanf("%d", &target);
    
    shannon_search(arr, 0, n-1, target);
    
    return 0;
}