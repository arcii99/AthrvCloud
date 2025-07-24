//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
// This is a searching algorithm that utilizes the power of math to find the target item in an array.

#include <stdio.h>

int jumpSearch(int arr[], int size, int target) {
    int jump = sqrt(size);
    int left = 0;
    int right = jump;
    
    while(arr[right] <= target && right < size) {
        left = right;
        right += jump;
        if(right > size - 1) {
            right = size;
        }
    }
    for(int i = left; i < right; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 8, 12, 16, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(int);
    int target = 16;
    int result = jumpSearch(arr, size, target);
    if(result == -1) {
        printf("Target element not found in array\n");
    } else {
        printf("Target element found at index: %d\n", result);
    }
    return 0;
}