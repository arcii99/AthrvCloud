//FormAI DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int left, int right, int value) {
    while (left <= right) {
        int middle = left + (right - left) / 2; // get the middle position of the array
 
        if (arr[middle] == value)
            return middle; // If value is found, return its index
    
        if (arr[middle] < value)
            left = middle + 1; // If value is greater than middle element, ignore left half
 
        else
            right = middle - 1; // If value is smaller than middle element, ignore right half
    }
 
    return -1; //If value is not found in the array, return -1
}

int main() {
    int n, i, value;
 
    printf("Enter size of array: ");
    scanf("%d", &n);
 
    int *arr = malloc(sizeof(int) * n); //Allocate memory for array
 
    printf("\nEnter array elements in sorted order: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    printf("\nEnter value to be searched: ");
    scanf("%d", &value);
 
    int pos = binarySearch(arr, 0, n - 1, value); // Call binary search function
 
    if(pos == -1)
        printf("\nValue not found in array");
    else
        printf("\nValue found at index: %d", pos);
}