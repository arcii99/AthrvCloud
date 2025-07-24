//FormAI DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int n, x, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int)); // memory allocation for array
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search:");
    scanf("%d", &x);
    int result = search(arr, n, x);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);
    free(arr); // free allocated memory
    return 0;
}