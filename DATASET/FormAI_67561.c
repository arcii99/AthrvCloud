//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int binary_search(int arr[], int left, int right, int x) {
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main(){
    int arr[] = { 2, 5, 9, 14, 22, 35, 47, 63 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22;
    int result = binary_search(arr, 0, n - 1, x);

    if (result != -1)
        printf("Element %d is present at index %d.", x, result);
    else
        printf("Element %d is not present in the array.", x);

    return 0;
}