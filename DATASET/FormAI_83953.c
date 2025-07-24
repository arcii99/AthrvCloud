//FormAI DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void bubble_sort(int* arr, int size);
void selection_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
void quick_sort(int* arr, int left, int right);
int partition(int* arr, int left, int right);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 87, 13, 40};
    int size = ARRAY_SIZE;

    // Bubble Sort
    printf("Bubble Sort:\n");
    bubble_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Selection Sort
    printf("Selection Sort:\n");
    selection_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Insertion Sort
    printf("Insertion Sort:\n");
    insertion_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Merge Sort
    printf("Merge Sort:\n");
    merge_sort(arr, 0, size-1);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Quick Sort
    printf("Quick Sort:\n");
    quick_sort(arr, 0, size-1);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void bubble_sort(int* arr, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int* arr, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int min_index = i;
        for(int j = i+1; j < size; j++)
            if(arr[j] < arr[min_index])
                min_index = j;

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int left_arr[left_size], right_arr[right_size];

    for(int i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];
    for(int i = 0; i < right_size; i++)
        right_arr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < left_size && j < right_size)
    {
        if(left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while(j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void quick_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int partition_index = partition(arr, left, right);

        quick_sort(arr, left, partition_index-1);
        quick_sort(arr, partition_index+1, right);
    }
}

int partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int i = left-1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i+1;
}