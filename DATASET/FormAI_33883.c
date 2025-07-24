//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int binarySearch(int array[], int size, int x)
{
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == x) {
            return mid;
        }
        else if (array[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int array[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(array) / sizeof(array[0]);
    int x = 10;

    int result = binarySearch(array, n, x);

    if (result == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d", result);
    }

    return 0;
}