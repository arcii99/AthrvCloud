//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

void fill_array(int *arr)
{
    int i;
    for(i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % ARR_SIZE;
    }
}

void copy_array(int *arr, int *copy)
{
    int i;
    for(i = 0; i < ARR_SIZE; i++)
    {
        copy[i] = arr[i];
    }
}

void bubble_sort(int *arr)
{
    int i, j, temp;
    for(i = 0; i < ARR_SIZE - 1; i++)
    {
        for(j = 0; j < ARR_SIZE - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        int j, temp;
        for(j = low; j <= high - 1; j++)
        {
            if(arr[j] < pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(int *arr)
{
    int i;
    for(i = 0; i < ARR_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[ARR_SIZE];
    int copy[ARR_SIZE];

    fill_array(arr);
    copy_array(arr, copy);

    printf("Bubble Sort\n");
    clock_t bubble_start = clock();
    bubble_sort(arr);
    clock_t bubble_end = clock();
    double bubble_time = (double)(bubble_end - bubble_start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", bubble_time);
    
    fill_array(copy);

    printf("\nQuick Sort\n");
    clock_t quick_start = clock();
    quick_sort(copy, 0, ARR_SIZE - 1);
    clock_t quick_end = clock();
    double quick_time = (double)(quick_end - quick_start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", quick_time);

    return 0;
}