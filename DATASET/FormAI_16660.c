//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        int mid = (i + j) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[i] <= arr[mid]) {
            if (x >= arr[i] && x < arr[mid]) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        else {
            if (x > arr[mid] && x <= arr[j]) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = { 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int result = search(arr, n, x);

    if (result == -1) {
        printf("Number %d is not present in the array\n", x);
    }
    else {
        printf("Number %d is present at index %d\n", x, result);
    }

    return 0;
}