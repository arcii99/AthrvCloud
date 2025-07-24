//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <time.h>

// Define the size of the array
#define SIZE 100000

// Define a function to fill the array with random integers
void fill_array(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Define a function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Define a function to bubble sort the array
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Define a function to measure the execution time of a function
double measure_time(void (*func)(int[], int), int arr[], int size) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    func(arr, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main() {
    // Declare an array of size SIZE
    int arr[SIZE];

    // Fill the array with random integers
    fill_array(arr, SIZE);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, SIZE);

    // Measure the execution time of bubble sort and print the sorted array
    printf("Sorted array:\n");
    double bubble_sort_time = measure_time(bubble_sort, arr, SIZE);
    print_array(arr, SIZE);

    // Print the execution time of bubble sort
    printf("Bubble sort execution time: %f seconds\n", bubble_sort_time);

    return 0;
}