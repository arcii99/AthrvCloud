//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates a unique searching algorithm in a retro style */
/* The algorithm searches for a specific element in an array of integers */

/* function declaration */
int retro_search(int arr[], int n, int key);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // the array to search from
    int n = sizeof(arr) / sizeof(arr[0]); // size of the array
    int key = 8; // the element to search for
    int index = retro_search(arr, n, key); // calling the search function

    // output the results based on the search function's return value
    if (index == -1)
    {
        printf("The element %d was not found in the array.\n", key);
    }
    else
    {
        printf("The element %d was found at position %d in the array.\n", key, index);
    }

    return 0;
}

/* This function searches for an element in an array of integers using a retro style algorithm */
int retro_search(int arr[], int n, int key)
{
    int i, j, k;

    // start searching from both sides of the array
    i = 0;
    j = n - 1;

    // perform the search in a zig-zag motion
    while(i <= j)
    {
        // search from left to right
        for(k = i; k <= j; k++)
        {
            if(arr[k] == key)
            {
                return k;
            }
        }
        // search from right to left
        for(k = j; k >= i; k--)
        {
            if(arr[k] == key)
            {
                return k;
            }
        }
        // element was not found in this segment, continue to the next segment
        i++;
        j--;
    }

    // element was not found in the array
    return -1;
}