//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>

// A custom searching function that searches for a number in an array
int search(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == x) {
            return mid;
        } 
        else if(arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 20;

    int result = search(arr, n, x);

    if (result == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d", result);
    }
    return 0;
}