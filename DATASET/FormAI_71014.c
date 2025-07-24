//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <time.h>

#define SIZE 100000

void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
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

void quick_sort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while(i < j)
        {
            while(arr[i] <= arr[pivot] && i < high)
            {
                i++;
            }
            while(arr[j] > arr[pivot])
            {
                j--;
            }
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
    }
}

int main()
{
    int arr[SIZE], i;
    srand(time(NULL)); // seed for random number generation
    
    // populate array with random integers between 1 and 100000
    printf("Generating random array of size %d...\n", SIZE);
    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100000 + 1;
    }
    
    // perform selection sort and time the process
    printf("Performing Selection Sort...\n");
    clock_t start = clock();
    selection_sort(arr, SIZE);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort took %.5f seconds\n", seconds);
    
    // perform bubble sort and time the process
    printf("Performing Bubble Sort...\n");
    start = clock();
    bubble_sort(arr, SIZE);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %.5f seconds\n", seconds);
    
    // perform quick sort and time the process
    printf("Performing Quick Sort...\n");
    start = clock();
    quick_sort(arr, 0, SIZE-1);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort took %.5f seconds\n", seconds);
    
    return 0;
}