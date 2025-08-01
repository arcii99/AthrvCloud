//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include<stdio.h>

void swap(int* a, int* b) //A function to swap the values
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) //A function to perform insertion sort
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) //A function to print the sorted array
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); //Finding the size of the array

    insertionSort(arr, n); //Performing the insertion sort

    printf("The sorted array is: \n"); //Printing the sorted array
    printArray(arr, n);

    return 0; 
}