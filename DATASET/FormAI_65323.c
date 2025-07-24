//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#define ARR_SIZE 10

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
 
        if (arr[mid] == target)
            return mid;
 
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
 
        return binarySearch(arr, mid + 1, right, target);
    }
 
    return -1;
}

int main() {
    int arr[ARR_SIZE] = {2, 6, 13, 21, 36, 47, 63, 81, 97, 118};
    int target = 36;
    int index = binarySearch(arr, 0, ARR_SIZE - 1, target);
 
    if (index != -1)
        printf("The target value of %d is located at index %d.", target, index);
    else
        printf("The target value of %d was not found in the array.", target);
 
    return 0;
}