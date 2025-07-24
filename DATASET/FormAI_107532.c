//FormAI DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void quick_sort(int[], int, int);
int partition(int[], int, int);
void insertion_sort(int[], int);
void merge(int[], int, int, int);
void merge_sort(int[], int, int);
double time_elapsed(clock_t, clock_t);

int main()
{
    int numbers[ARRAY_SIZE], numbers_copy[ARRAY_SIZE];
    int i, j;
    clock_t start, end;
    double elapsed_time;

    // generate random numbers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        numbers[i] = rand() % 100000;
        numbers_copy[i] = numbers[i];
    }

    printf("Benchmarking C Sorting Algorithms\n");

    // quick sort
    start = clock();
    quick_sort(numbers, 0, ARRAY_SIZE - 1);
    end = clock();
    elapsed_time = time_elapsed(start, end);
    printf("Quick Sort: %f seconds\n", elapsed_time);

    // insertion sort
    for (i = 0; i < ARRAY_SIZE; i++)
        numbers[i] = numbers_copy[i]; // reset the array
    start = clock();
    insertion_sort(numbers, ARRAY_SIZE);
    end = clock();
    elapsed_time = time_elapsed(start, end);
    printf("Insertion Sort: %f seconds\n", elapsed_time);

    // merge sort
    for (i = 0; i < ARRAY_SIZE; i++)
        numbers[i] = numbers_copy[i]; // reset the array
    start = clock();
    merge_sort(numbers, 0, ARRAY_SIZE - 1);
    end = clock();
    elapsed_time = time_elapsed(start, end);
    printf("Merge Sort: %f seconds\n", elapsed_time);

    return 0;
}

void quick_sort(int numbers[], int left, int right)
{
    int i, j, pivot, temp;
    if (left < right)
    {
        pivot = partition(numbers, left, right);
        quick_sort(numbers, left, pivot - 1);
        quick_sort(numbers, pivot + 1, right);
    }
}

int partition(int numbers[], int left, int right)
{
    int pivot, i, j, temp;
    pivot = numbers[right];
    i = left - 1;
    for (j = left; j < right; j++)
    {
        if (numbers[j] <= pivot)
        {
            i++;
            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }
    temp = numbers[i + 1];
    numbers[i + 1] = numbers[right];
    numbers[right] = temp;
    return i + 1;
}

void insertion_sort(int numbers[], int length)
{
    int i, j, temp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && numbers[j - 1] > numbers[j])
        {
            // swap
            temp = numbers[j - 1];
            numbers[j - 1] = numbers[j];
            numbers[j] = temp;
            j--;
        }
    }
}

void merge(int numbers[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = numbers[left + i];
    for (j = 0; j < n2; j++)
        R[j] = numbers[mid + 1 + j];

    // merge
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            numbers[k] = L[i];
            i++;
        }
        else
        {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements from L and R into numbers
    while (i < n1)
    {
        numbers[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        numbers[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int numbers[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(numbers, left, mid);
        merge_sort(numbers, mid + 1, right);
        merge(numbers, left, mid, right);
    }
}

double time_elapsed(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}