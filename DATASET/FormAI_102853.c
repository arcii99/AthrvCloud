//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include<stdio.h>

int search(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to search:\n");
    scanf("%d", &key);
    int result = search(arr, n, key);
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index: %d\n", result);
    return 0;
}