//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void print_array(int arr[], int size);

int main()
{
    int arr[] = {4, 9, 2, 7, 5, 8, 1, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print_array(arr, size);

    printf("\nBubble Sort: ");
    bubble_sort(arr, size);
    print_array(arr, size);

    int arr2[] = {4, 9, 2, 7, 5, 8, 1, 3, 6};

    printf("\nSelection Sort: ");
    selection_sort(arr2, size);
    print_array(arr2, size);

    int arr3[] = {4, 9, 2, 7, 5, 8, 1, 3, 6};

    printf("\nInsertion Sort: ");
    insertion_sort(arr3, size);
    print_array(arr3, size);

    return 0;
}

// Bubble sort algorithm
void bubble_sort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Selection sort algorithm
void selection_sort(int arr[], int size)
{
    int i, j, min_index, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Insertion sort algorithm
void insertion_sort(int arr[], int size)
{
    int i, j, temp;

    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Function to print the array
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}