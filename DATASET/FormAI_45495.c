//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>

int mind_bending_search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
 
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        int pos = low + (((double)(high-low) / (arr[high]-arr[low])) * (x - arr[low]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            low = pos + 1;
 
        else
            high = pos - 1;
    }
 
    return -1;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
 
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
 
    int result = mind_bending_search(arr, n, x);
    (result == -1) ? printf("Element is not present in array") :
                   printf("Element is present at index %d",result);
    return 0;
}