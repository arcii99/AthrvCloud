//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#define MAX_SIZE 100

int search(int arr[], int size, int key);

int main()
{
    int arr[MAX_SIZE];
    int size, key, index;

    printf("Enter the size of an array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element to search: ");
    scanf("%d", &key);

    index = search(arr, size, key);

    if(index == -1)
        printf("Element not found in the array!\n");
    else
        printf("Element found at index %d.\n", index);

    return 0;
}

int search(int arr[], int size, int key)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}