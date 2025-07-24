//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void bubbleSort(int array[], int size);
void quickSort(int array[], int start, int end);

int main()
{
    int i, j, array[MAX];
    double bubbleTime, quickTime;
    clock_t start, end;

    srand(time(NULL));

    // Generate random values for array
    for (i = 0; i < MAX; i++) {
        array[i] = rand();
    }

    // Benchmark Bubble Sort
    start = clock();
    bubbleSort(array, MAX);
    end = clock();
    bubbleTime = ((double) end - start) / CLOCKS_PER_SEC;

    // Generate random values for array again
    for (i = 0; i < MAX; i++) {
        array[i] = rand();
    }

    // Benchmark Quick Sort
    start = clock();
    quickSort(array, 0, MAX - 1);
    end = clock();
    quickTime = ((double) end - start) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %f seconds\n", bubbleTime);
    printf("Quick Sort Time: %f seconds\n", quickTime);

    return 0;
}

void bubbleSort(int array[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void quickSort(int array[], int start, int end)
{
    int pivot, i = start, j = end, temp;

    if (start < end) {
        pivot = start;

        while (i < j) {
            while (array[i] <= array[pivot] && i < end) {
                i++;
            }

            while (array[j] > array[pivot]) {
                j--;
            }

            if (i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;

        quickSort(array, start, j - 1);
        quickSort(array, j + 1, end);
    }
}