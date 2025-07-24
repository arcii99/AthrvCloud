//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000000

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

void printArray(int arr[], int n) 
{
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main() 
{
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    /* generate random array */
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand();
    }

    printf("Before Sorting:\n");
    //printArray(arr, ARRAY_SIZE);

    start = clock();
    mergeSort(arr, 0, ARRAY_SIZE - 1);
    end = clock();

    printf("After Sorting:\n");
    //printArray(arr, ARRAY_SIZE);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %f seconds", cpu_time_used);

    return 0;
}