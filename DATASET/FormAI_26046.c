//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int recursive_search(int arr[], int start, int end, int element);

int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int element = 70;
    int index = recursive_search(arr, 0, 9, element);

    if(index != -1)
    {
        printf("%d is found at index %d.\n", element, index);
    }
    else
    {
        printf("%d was not found in the array.\n", element);
    }

    return 0;
}

int recursive_search(int arr[], int start, int end, int element)
{
    int mid = (start + end) / 2;

    if(start > end)
    {
        return -1;
    }

    if(arr[mid] == element)
    {
        return mid;
    }
    else if(arr[mid] > element)
    {
        return recursive_search(arr, start, mid - 1, element);
    }
    else
    {
        return recursive_search(arr, mid + 1, end, element);
    }
}