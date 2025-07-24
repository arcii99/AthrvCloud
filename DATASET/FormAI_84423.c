//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int binary_search(int arr[], int left, int right, int x){
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);

        // Else the element is in right side
        return binary_search(arr, mid + 1, right, x);
    }

    // If element is not present in array
    return -1;
}

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binary_search(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element is not present in array.");
    else
        printf("Element is present at index %d.", result);

    return 0;
}