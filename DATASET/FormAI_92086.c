//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_RANDOM 100

// Function to populate an array with random integers
void populateArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        array[i] = rand() % MAX_RANDOM;
    }
}

// Function to print an array
void printArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to sort an array using bubble sort algorithm
void bubbleSort(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int array[ARRAY_SIZE];
    srand(time(0)); // Seed rand() function with current time
    populateArray(array, ARRAY_SIZE);
    printf("Unsorted Array:\n");
    printArray(array, ARRAY_SIZE);
    bubbleSort(array, ARRAY_SIZE);
    printf("Sorted Array:\n");
    printArray(array, ARRAY_SIZE);
    return 0;
}