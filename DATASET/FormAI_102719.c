//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>

int binary_search(int arr[], int left, int right, int target);

int main()
{
    int n, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array (in ascending order): ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the target element to be searched: ");
    scanf("%d", &target);
    int res = binary_search(arr, 0, n-1, target);
    if(res != -1)
        printf("The target element is present in the array at index %d.\n", res);
    else
        printf("The target element is not present in the array.\n");

    return 0;
}

int binary_search(int arr[], int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}