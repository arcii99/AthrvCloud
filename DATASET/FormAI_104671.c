//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random input generator
void generate_input(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;  // generates random numbers between 1 to 100
    }
}

// Print the array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sorting functions
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n = 10;   // Number of elements to be sorted
    int arr[n];   // Array to be sorted

    // Generate random input
    generate_input(arr, n);

    printf("Before sorting:\n");
    print_arr(arr, n);

    printf("\nBubble sort:\n");
    bubble_sort(arr, n);
    print_arr(arr, n);

    printf("\nSelection sort:\n");
    selection_sort(arr, n);
    print_arr(arr, n);

    printf("\nInsertion sort:\n");
    insertion_sort(arr, n);
    print_arr(arr, n);

    return 0;
}