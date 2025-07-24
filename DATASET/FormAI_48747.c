//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include<stdio.h>
#define MAXSIZE 100

int RetroSearch(int arr[],int n, int key);

int main()
{
    int arr[MAXSIZE], i, n, key, position;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    position = RetroSearch(arr,n,key);
    if(position == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element found at position %d\n",position);
    }

    return 0;
}

int RetroSearch(int arr[],int n, int key)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(arr[i] == key)
        {
            return i+1;
        }
    }
    return -1;

}