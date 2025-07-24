//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int paranoid_search(int arr[], int n, int x)
{
    int left = 0, right = n - 1; // initialize left and right pointers
    while (left <= right) // perform binary search
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x) // if element is found, return its index
        {
            printf("Element found!\n");
            return mid;
        }
        else if (arr[mid] < x) // if element is greater than mid, search in right half
        {
            printf("Searching in the right half!\n");
            left = mid + 1;
        }
        else // if element is smaller than mid, search in left half
        {
            printf("Searching in the left half!\n");
            right = mid - 1;
        }
    }
    printf("Element not found!\n"); // if element is not found, return -1
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    paranoid_search(arr, n, x);
    return 0;
}