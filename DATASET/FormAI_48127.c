//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants and global variables */
#define ARRAY_SIZE 1000000
int array1[ARRAY_SIZE];
int array2[ARRAY_SIZE];
int array3[ARRAY_SIZE];
clock_t start, end;
double cpu_time;

/* Function to generate random integers */
void fill_array(int *array, int size)
{
    int i;
    srand(time(NULL));
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 1000000;
    }
}

/* Function to swap two integers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Implementation of the bubble sort algorithm */
void bubble_sort(int *array, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/* Implementation of the insertion sort algorithm */
void insertion_sort(int *array, int size)
{
    int i, j;
    int key;
    for(i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = key;
    }
}

/* Implementation of the selection sort algorithm */
void selection_sort(int *array, int size)
{
    int i, j, min_idx;
    for(i = 0; i < size-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < size; j++)
        {
            if(array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&array[min_idx], &array[i]);
    }
}

/* Main function */
int main()
{
    /* Fill the arrays with random integers */
    fill_array(array1, ARRAY_SIZE);
    fill_array(array2, ARRAY_SIZE);
    fill_array(array3, ARRAY_SIZE);

    /* Start the clock and run the bubble sort */
    start = clock();
    bubble_sort(array1, ARRAY_SIZE);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort:\t\t%f seconds\n", cpu_time);

    /* Start the clock and run the insertion sort */
    start = clock();
    insertion_sort(array2, ARRAY_SIZE);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort:\t\t%f seconds\n", cpu_time);

    /* Start the clock and run the selection sort */
    start = clock();
    selection_sort(array3, ARRAY_SIZE);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort:\t\t%f seconds\n", cpu_time);

    return 0;
}