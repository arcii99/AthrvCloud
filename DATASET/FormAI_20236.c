//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

int binary_search(int arr[], int n, int x)
{
    int left = 0, right = n - 1, mid;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main()
{
    int n, x, i;
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Enter the number you want to search: ");
    scanf("%d", &x);
    
    i = binary_search(arr, n, x);
    
    if (i == -1)
        printf("The number is not found.\n");
    else
        printf("The number is found at index %d.\n", i);
    
    return 0;
}