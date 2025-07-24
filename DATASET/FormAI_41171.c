//FormAI DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000 // Number of elements in the array

// Function to generate random numbers
void generate_numbers(int arr[]) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function to print the array
void print_array(int arr[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort
void bubble_sort(int arr[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort the array using quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Main function to run the benchmark tests
int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    // Test the bubble sort algorithm
    generate_numbers(arr);
    printf("Before sorting (bubble sort): ");
    print_array(arr);
    start = clock();
    bubble_sort(arr);
    end = clock();
    printf("After sorting (bubble sort): ");
    print_array(arr);
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);

    // Test the quick sort algorithm
    generate_numbers(arr);
    printf("Before sorting (quick sort): ");
    print_array(arr);
    start = clock();
    quick_sort(arr, 0, N - 1);
    end = clock();
    printf("After sorting (quick sort): ");
    print_array(arr);
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}