//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
/* Ken Thompson Style C Searching Algorithm Program */
#include <stdio.h>

int search(int arr[], int target, int n) {
    int left = 0, right = n - 1;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = search(arr, target, n);
    if(result == -1) {
        printf("Element is not present in array\n");
    }
    else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}