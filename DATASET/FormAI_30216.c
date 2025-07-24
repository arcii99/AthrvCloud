//FormAI DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>

// function to search for an element in array using linear search
int linearSearch(int arr[], int n, int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }   

    return -1;
}

// function to sort the array using bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// function to search for an element in array using binary search
int binarySearch(int arr[], int l, int r, int x)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x)
        {
            return mid;
        }
        if(arr[mid] > x)
        {
            return binarySearch(arr, l, mid-1, x);
        }
        return binarySearch(arr, mid+1, r, x);
    }

    return -1;
}

int main()
{
    int arr[] = {5, 3, 2, 8, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    // search for x using linear search
    int index = linearSearch(arr, n, x);

    if(index == -1)
    {
        printf("%d not found in the array using linear search\n", x);
    }
    else
    {
        printf("%d found in the array at index %d using linear search\n", x, index);
    }

    // sort the array using bubble sort
    bubbleSort(arr, n);

    // search for x using binary search
    index = binarySearch(arr, 0, n-1, x);

    if(index == -1)
    {
        printf("%d not found in the array using binary search\n", x);
    }
    else
    {
        printf("%d found in the array at index %d using binary search\n", x, index);
    }

    return 0;
}