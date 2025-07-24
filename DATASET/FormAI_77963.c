//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int n, int x)
{
    int left = 0, right = n-1; //defining the leftmost and rightmost boundaries
    while (left <= right) { //while the leftmost boundary is less than or equal to the rightmost boundary, move the boundaries inward
        
        int mid = left + (right - left) / 2; //calculate the middle index
        
        if (arr[mid] == x) //if the mid element is the searched element
            return mid; 

        if (arr[mid] < x) //if the mid element is less than the searched element, search in the right half of the array
            left = mid + 1;

        else //if the mid element is greater than the searched element, search in the left half of the array
            right = mid - 1;
    }

    return -1; //return -1 if the element is not present in the array
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr)/sizeof(arr[0]); //determine the size of the array
    int x = 30; //element to be searched
    int result = search(arr, n, x); //calling the search function

    if (result == -1)
        printf("Element not present in array");
    else
        printf("Element present at index %d", result);
    return 0;
}