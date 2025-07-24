//FormAI DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000

int main()
{
    clock_t start, end;
    double cpu_time_used;

    // Generate a random array
    int arr[MAX_ARRAY_SIZE];
    srand(time(0));
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    // Bubble sort implementation
    start = clock();
    for (int i = 0; i < MAX_ARRAY_SIZE - 1; i++)
    {
        for (int j = 0; j < MAX_ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort\n");
    printf("Time taken: %lf seconds\n", cpu_time_used);

    // Merge sort implementation
    start = clock();
    mergeSort(arr, 0, MAX_ARRAY_SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Merge Sort\n");
    printf("Time taken: %lf seconds\n", cpu_time_used);

    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}