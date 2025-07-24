//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>

/* Simple linear search algorithm to find an element in an array */

int linear_search(int arr[], int n, int x) 
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
    int n, i, x, result;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    result = linear_search(arr, n, x);
    if (result == -1) {
        printf("Element not found in array\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}