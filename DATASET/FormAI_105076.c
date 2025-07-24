//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bubble_sort(int*, int);
void insertion_sort(int*, int);
void selection_sort(int*, int);
void quick_sort(int*, int, int);
void merge_sort(int*, int, int);

int main()
{
    int input_sizes[] = {1000, 5000, 10000, 50000, 100000};
    double bubble_sort_times[5], insertion_sort_times[5], selection_sort_times[5], quick_sort_times[5], merge_sort_times[5];

    for(int i=0; i<5; i++)
    {
        int input_size = input_sizes[i];
        int input_array[MAX_SIZE];

        // Generate random input array
        srand(time(NULL));
        for(int j=0; j<input_size; j++)
            input_array[j] = rand() % MAX_SIZE;

        clock_t start_time, end_time;

        // Bubble Sort
        start_time = clock();
        bubble_sort(input_array, input_size);
        end_time = clock();
        bubble_sort_times[i] = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Insertion Sort
        start_time = clock();
        insertion_sort(input_array, input_size);
        end_time = clock();
        insertion_sort_times[i] = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Selection Sort
        start_time = clock();
        selection_sort(input_array, input_size);
        end_time = clock();
        selection_sort_times[i] = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Quick Sort
        start_time = clock();
        quick_sort(input_array, 0, input_size-1);
        end_time = clock();
        quick_sort_times[i] = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Merge Sort
        start_time = clock();
        merge_sort(input_array, 0, input_size-1);
        end_time = clock();
        merge_sort_times[i] = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Input size: %d\nBubble Sort time: %f seconds\nInsertion Sort time: %f seconds\nSelection Sort time: %f seconds\nQuick Sort time: %f seconds\nMerge Sort time: %f seconds\n\n", input_size, bubble_sort_times[i], insertion_sort_times[i], selection_sort_times[i], quick_sort_times[i], merge_sort_times[i]);
    }

    return 0;
}

void bubble_sort(int* arr, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void insertion_sort(int* arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selection_sort(int* arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[min_index])
                min_index = j;

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void quick_sort(int* arr, int low, int high)
{
    if(low < high)
    {
        int pivot = arr[low];
        int i = low+1;
        int j = high;
        while(i <= j)
        {
            while(i <= j && arr[i] <= pivot)
                i++;
            while(i <= j && arr[j] > pivot)
                j--;
            if(i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
    }
}

void merge_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left+right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        int i = left, j = mid+1, k = 0;
        int temp[MAX_SIZE];
        while(i <= mid && j <= right)
        {
            if(arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while(i <= mid)
            temp[k++] = arr[i++];
        while(j <= right)
            temp[k++] = arr[j++];

        for(i=left, k=0; i<=right; i++, k++)
            arr[i] = temp[k];
    }
}