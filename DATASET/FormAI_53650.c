//FormAI DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>

// Function to perform binary search on an array of integers
int binary_search(int arr[], int n, int x)
{
    int left = 0, right = n-1, mid;
    while(left <= right)
    {
        mid = (left + right) / 2; // calculate mid index of array
        if(arr[mid] == x) // found the element
            return mid;
        else if(arr[mid] < x) // search in right half of array
            left = mid + 1;
        else // search in left half of array
            right = mid - 1;
    }
    return -1; // element not found
}

int main()
{
    int arr[] = {2, 5, 7, 9, 11, 14, 16, 19, 20, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int index = binary_search(arr, n, x);

    if(index != -1)
        printf("\nElement %d found at index %d\n", x, index);
    else
        printf("\nElement not found in array\n");

    return 0;
}