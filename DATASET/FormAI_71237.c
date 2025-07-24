//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10000000

//Function for shuffling the array
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

//Function for Bubble Sort
void bubbleSort(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//Function for Quick Sort
void quickSort(int *array, int low, int high)
{
    int i = low, j = high, temp;
    int pivot = array[(low + high) / 2];

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i++] = array[j];
            array[j--] = temp;
        }
    }

    if (low < j)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main()
{
    int arr[ArraySize]; //Array of size 10,000,000
    clock_t t1, t2;
    double bubble_sort_time, quick_sort_time;

    srand(time(0)); //Setting seed for rand function

    //Populating the array in ascending order
    for (int i = 0; i < ArraySize; i++)
    {
        arr[i] = i;
    }

    //Measuring time taken for Bubble Sort on the sorted array
    t1 = clock();
    bubbleSort(arr, ArraySize);
    t2 = clock();
    bubble_sort_time = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    //Measuring time taken for Quick Sort on the sorted array
    t1 = clock();
    quickSort(arr, 0, ArraySize - 1);
    t2 = clock();
    quick_sort_time = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    printf("Time taken for Bubble Sort on sorted array of size %d: %lf seconds\n", ArraySize, bubble_sort_time);
    printf("Time taken for Quick Sort on sorted array of size %d: %lf seconds\n", ArraySize, quick_sort_time);

    //Shuffling the array
    shuffle(arr, ArraySize);

    //Measuring time taken for Bubble Sort on the shuffled array
    t1 = clock();
    bubbleSort(arr, ArraySize);
    t2 = clock();
    bubble_sort_time = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    //Measuring time taken for Quick Sort on the shuffled array
    t1 = clock();
    quickSort(arr, 0, ArraySize - 1);
    t2 = clock();
    quick_sort_time = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    printf("Time taken for Bubble Sort on shuffled array of size %d: %lf seconds\n", ArraySize, bubble_sort_time);
    printf("Time taken for Quick Sort on shuffled array of size %d: %lf seconds\n", ArraySize, quick_sort_time);

    return 0;
}