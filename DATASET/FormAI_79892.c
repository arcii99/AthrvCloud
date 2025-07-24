//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

// Function prototypes
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void print_array(int arr[], int n);

int main()
{
    int arr[SIZE], arr1[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE], i;
    clock_t t1, t2;

    // Generate random array of integers
    for(i=0; i<SIZE; i++)
    {
        arr1[i] = rand() % 10000;
    }

    // Copy array for different sorting algorithms
    for(i=0; i<SIZE; i++)
    {
        arr[i] = arr1[i];
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

    // Bubble Sort
    t1 = clock();
    bubble_sort(arr, SIZE);
    t2 = clock();
    printf("\nBubble Sort Time taken: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    // Selection Sort
    t1 = clock();
    selection_sort(arr1, SIZE);
    t2 = clock();
    printf("\nSelection Sort Time taken: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    // Insertion Sort
    t1 = clock();
    insertion_sort(arr2, SIZE);
    t2 = clock();
    printf("\nInsertion Sort Time taken: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    // Merge Sort
    t1 = clock();
    merge_sort(arr3, 0, SIZE-1);
    t2 = clock();
    printf("\nMerge Sort Time taken: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    // Quick Sort
    t1 = clock();
    quick_sort(arr4, 0, SIZE-1);
    t2 = clock();
    printf("\nQuick Sort Time taken: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for(i=0; i<n-1; i++)
    {
        min_idx = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i=0; i<n1; i++)
    {
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
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

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}