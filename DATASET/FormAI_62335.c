//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

// Recursive function to calculate checksum
int checksum(int arr[], int n)
{
    if(n == 0) // base case, when array size becomes 0
    {
        return 0;
    }
    else
    {
        return (arr[n-1] + checksum(arr, n-1)); // recursive call
    }
}

int main()
{
    int arr[10], n, i, sum;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    sum = checksum(arr, n); // function call to calculate checksum
    
    printf("Checksum of the array is: %d", sum);
    
    return 0;
}