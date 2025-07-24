//FormAI DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5000000

int main()
{
    int i, j, k, temp;
    double elapsed_time;
    
    clock_t start, end;
    int array[ARRAY_SIZE];
    
    //generate random integers for the array
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand();
    }
    
    //Bubble sort implementation
    start = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++)
    {
        for(j = 0; j < ARRAY_SIZE-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                //swap elements if they are in wrong order
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("\nTime taken by bubble sort to sort array of size %d: %f seconds", ARRAY_SIZE, elapsed_time);
    
    //Selection sort implementation
    start = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++)
    {
        int min_index = i;
        for(j = i+1; j < ARRAY_SIZE; j++)
        {
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        //swap elements if they are in wrong order
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
    end = clock();
    
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("\nTime taken by selection sort to sort array of size %d: %f seconds", ARRAY_SIZE, elapsed_time);
    
    //Quick sort implementation
    start = clock();
    quick_sort(array, 0, ARRAY_SIZE-1);
    end = clock();
    
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("\nTime taken by quick sort to sort array of size %d: %f seconds", ARRAY_SIZE, elapsed_time);
    
    return 0;
}

//helper function for Quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low-1);
    
    for(int j = low; j <= high-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            //swap elements if they are in wrong order
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap elements if they are in wrong order
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    
    return (i+1);
}

//Quick sort recursive function
void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}