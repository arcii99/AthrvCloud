//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>

int binarySearch(int *arr, int n, int x) {

    int low = 0, high = n-1;

    while(low <= high) {

        int mid = low + (high-low)/2;

        if(arr[mid] == x) {
            return mid;
        }

        if(arr[mid] < x) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }

    }

    return -1;

}

int main() {

    int arr[] = {-10, -1, 7, 15, 32, 98, 102, 500};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 102;
    int result = binarySearch(arr, n, x);

    if(result == -1) {
        printf("%d not found in array.\n", x);
    }

    else {
        printf("%d found at index %d.\n", x, result);
    }

    return 0;

}