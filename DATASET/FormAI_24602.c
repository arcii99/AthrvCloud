//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>

int search(int arr[], int n, int x, int y, int z)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x || arr[i] == y || arr[i] == z)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = { 2, 7, 15, 27, 13, 23, 8, 21, 19, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 21, y = 19, z = 8;

    int result = search(arr, n, x, y, z);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}