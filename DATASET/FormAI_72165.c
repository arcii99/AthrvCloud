//FormAI DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>

int csearch(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;
    if (r >= l)
    {
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return csearch(arr, l, mid - 1, x);

        return csearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int n, arr[100], x, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in sorted order: ");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search for: ");
    scanf("%d", &x);
    result = csearch(arr, 0, n-1, x);
    if (result == -1)
        printf("Element not found in array");
    else
        printf("Element found at index %d", result);
    return 0;
}