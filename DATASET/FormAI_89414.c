//FormAI DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void printArray(int arr[], int size);

int main()
{
    int arr[SIZE];
    srand(time(0));
    
    printf("Generating a random array of size %d...\n", SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    printArray(arr, SIZE);
    
    printf("\nSorting the array using Bubble Sort...\n");
    bubbleSort(arr, SIZE);
    printArray(arr, SIZE);
    
    printf("\nSorting the array using Insertion Sort...\n");
    insertionSort(arr, SIZE);
    printArray(arr, SIZE);
    
    printf("\nSorting the array using Selection Sort...\n");
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);
    
    return 0;
}

void bubbleSort(int arr[], int size)
{
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
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

void insertionSort(int arr[], int size)
{
    int i, j, temp;
    for(i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int size)
{
    int i, j, temp, min_idx;
    for(i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size)
{
    printf("[ ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}