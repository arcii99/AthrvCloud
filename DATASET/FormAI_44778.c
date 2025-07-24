//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define MAX_VALUE 1000

void quick_sort(int *arr, int left, int right);
void insertion_sort(int *arr, int size);
void performance_test(int *arr, int size);

int main()
{
    // generate random array
    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % MAX_VALUE;
    }

    performance_test(arr, SIZE);

    return 0;
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = arr[(left + right) / 2];
        int i = left - 1;
        int j = right + 1;

        while (1)
        {
            do
            {
                i++;
            } while (arr[i] < pivot);

            do
            {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
            {
                break;
            }

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        quick_sort(arr, left, j);
        quick_sort(arr, j + 1, right);
    }
}

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void performance_test(int *arr, int size)
{
    printf("Sorting an array of size %d\n", size);

    // test quick sort
    clock_t start_time = clock();
    quick_sort(arr, 0, size - 1);
    clock_t end_time = clock();
    printf("Quick sort took %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // test insertion sort
    start_time = clock();
    insertion_sort(arr, size);
    end_time = clock();
    printf("Insertion sort took %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
}