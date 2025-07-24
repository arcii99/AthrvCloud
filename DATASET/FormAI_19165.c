//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include<stdio.h>
#define MAX_SIZE 100  // maximum size of array

int main()
{
    int arr[MAX_SIZE], i, n, key;
    printf("Enter the size of array: ");
    scanf("%d", &n);  // input size of array from user

    // input array elements
    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // input key element to be searched
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    // linear search algorithm
    for(i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            printf("%d is present at index %d.\n", key, i+1);
            break;  // exit loop if key is found
        }
    }

    if(i == n)
    {
        printf("%d is not present in the array.\n", key);
    }

    return 0;
}