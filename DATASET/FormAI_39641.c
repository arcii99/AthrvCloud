//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>

// insert futuristic searching algorithm here
int futuristic_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + (((double)(high-low) / (arr[high]-arr[low])) * (key - arr[low]));
        
        if (arr[pos] == key) {
            return pos;
        }
        
        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    
    int result = futuristic_search(arr, n, key);
    
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}