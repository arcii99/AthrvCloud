//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n, int key) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int n, key, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int pos = search(arr, n, key);
    if (pos == -1) 
    {
        printf("Element not found\n");
    } 
    else 
    {
        printf("Element found at position %d\n", pos);
    }
    return 0;
}