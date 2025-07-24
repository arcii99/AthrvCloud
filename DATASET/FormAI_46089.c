//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element to be searched: ");
    scanf("%d", &key);
    int result = linearSearch(arr,n,key);
    if(result!=-1)
    {
        printf("\nThe key element is found at position: %d\n", result+1);
    }
    else
    {
        printf("\nThe key element is not found in the array :(");
    }
    return 0;
}