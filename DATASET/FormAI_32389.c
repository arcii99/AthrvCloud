//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = { 2,3,4,5,6,7,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Element is not present in array\n");
    }
    else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}