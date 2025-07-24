//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

// define sorting functions
void insertion_sort(int* arr, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quick_sort(int* arr, int left, int right)
{
    int i, j, pivot, temp;
    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;
 
        while (i < j) 
        {
            while (arr[i] <= arr[pivot] && i < right)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quick_sort(arr, left, j - 1);
        quick_sort(arr, j + 1, right);
    }
}

void merge_sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
 
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
 
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;
 
        int L[n1], R[n2];
 
        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
 
        i = 0;
        j = 0;
        k = left;
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
}

// main function
int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % SIZE;
 
    clock_t t;
 
    // measure insertion sort time
    t = clock();
    insertion_sort(arr, SIZE);
    t = clock() - t;
    printf("Insertion Sort took %f seconds to execute \n", ((double)t) / CLOCKS_PER_SEC);
 
    // measure quick sort time
    t = clock();
    quick_sort(arr, 0, SIZE - 1);
    t = clock() - t;
    printf("Quick Sort took %f seconds to execute \n", ((double)t) / CLOCKS_PER_SEC);
 
    // measure merge sort time
    t = clock();
    merge_sort(arr, 0, SIZE - 1);
    t = clock() - t;
    printf("Merge Sort took %f seconds to execute \n", ((double)t) / CLOCKS_PER_SEC);
 
    return 0;
}