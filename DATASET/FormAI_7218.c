//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>

// Swap function to swap the elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
// Function to perform insertion sort
void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
 
// Performs selection sort
void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
 
// Performs Bubble sort
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
// Prints the given array
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver function
int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Unsorted array: ");
    print_array(arr, n);
 
    insertion_sort(arr, n);
    printf("Array after Insertion Sort: ");
    print_array(arr, n);

    selection_sort(arr, n);
    printf("Array after Selection Sort: ");
    print_array(arr, n);
 
    bubble_sort(arr, n);
    printf("Array after Bubble sort: ");
    print_array(arr, n);
 
    return 0;
}