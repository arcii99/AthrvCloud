//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the array to be sorted

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main()
{
    int arr[SIZE];
    int i;

    // fill an array with random numbers
    srand(time(NULL)); // seed rand() with the current time
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100; // get a random number between 0 and 99
    }

    printf("Original array:\n");
    printArray(arr, SIZE);

    printf("\nSorting the array using bubble sort...\n");
    bubbleSort(arr, SIZE);
    printf("\nSorted array using bubble sort:\n");
    printArray(arr, SIZE);

    printf("\nSorting the array using selection sort...\n");
    selectionSort(arr, SIZE);
    printf("\nSorted array using selection sort:\n");
    printArray(arr, SIZE);

    printf("\nSorting the array using insertion sort...\n");
    insertionSort(arr, SIZE);
    printf("\nSorted array using insertion sort:\n");
    printArray(arr, SIZE);

    return 0;
}

// print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// bubble sort algorithm
void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1]) // swap if the two elements are in the wrong order
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// selection sort algorithm
void selectionSort(int arr[], int size)
{
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]) // find the minimum element in the unsorted part of the array
            {
                minIndex = j;
            }
        }
        if (minIndex != i) // swap the minimum element with the first element in the unsorted part of the array
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// insertion sort algorithm
void insertionSort(int arr[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = arr[i]; // store the current element for insertion
        j = i - 1;
        while (j >= 0 && arr[j] > temp) // shift all larger elements to the right
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; // insert the current element into the correct position
    }
}