//FormAI DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int left, int right, int num) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
            return mid;

        if (arr[mid] < num)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[10] = {12, 24, 35, 46, 57, 68, 79, 80, 91, 102};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int num = 80;

    int result = BinarySearch(arr, 0, arr_size - 1, num);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    
    return 0;
}