//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int hybridSearch(int arr[], int n, int target) {
    // Linear Search
    int left = 0, right = n-1;
    while (left <= right) {
        if (arr[left] == target)
            return left;
        else if (arr[right] == target)
            return right;
        left++;
        right--;
    }
    // Binary Search
    int middle, start = left;
    left = start, right = n-1;
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == target)
            return middle;
        else if (arr[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1; // target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    int result = hybridSearch(arr, n, target);
    if (result == -1)
        printf("Target value not found.\n");
    else
        printf("Target value found at index %d.\n", result);
    return 0;
}