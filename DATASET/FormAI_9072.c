//FormAI DATASET v1.0 Category: Sorting ; Style: detailed
//This program is an example of sorting an array of integers in ascending order using selection sort algorithm.

#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    //outer loop to traverse the array
    for (i = 0; i < n - 1; i++)
    {
        min = i; //initialize the minimum element to the first element of unsorted array

        //inner loop to find the minimum element in the unsorted array
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; //update the index of minimum element
            }
        }

        //swap the minimum element with the first element of unsorted array
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {23, 10, 75, 20, 54, 55, 89, 5}; //initialize the array
    int n = sizeof(arr) / sizeof(arr[0]); //find the size of array

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); //print the array before sorting
    }

    selectionSort(arr, n); //call the selection sort function

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); //print the array after sorting
    }

    return 0;
}