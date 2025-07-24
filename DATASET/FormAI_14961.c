//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // element not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = binary_search(arr, n, x);
    
    if (index == -1)
        printf("Element not found!");
    else
        printf("Element found at position %d", index+1);
    
    return 0;
}