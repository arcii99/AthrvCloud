//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 5000

// Function to fill the array with random integers
void fill_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 5000;
    }
}

// Function to print the contents of the array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Bubble sort algorithm
void bubble_sort(int* array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Quick sort algorithm
void quick_sort(int* array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int partition_index = i + 1;

        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];
    fill_array(array1, ARRAY_SIZE); // fill the array with random integers
    print_array(array1, ARRAY_SIZE); // print the unsorted array

    printf("\nPerforming bubble sort...\n");
    clock_t bubble_start = clock();
    bubble_sort(array1, ARRAY_SIZE); // sort the array using bubble sort
    clock_t bubble_end = clock();
    double bubble_time_elapsed = (double)(bubble_end - bubble_start) / CLOCKS_PER_SEC;
    printf("\nSorted array using bubble sort:\n");
    print_array(array1, ARRAY_SIZE); // print the sorted array
    printf("Bubble sort time: %f seconds\n", bubble_time_elapsed);

    fill_array(array2, ARRAY_SIZE); // fill the array with random integers
    print_array(array2, ARRAY_SIZE); // print the unsorted array

    printf("\nPerforming quick sort...\n");
    clock_t quick_start = clock();
    quick_sort(array2, 0, ARRAY_SIZE - 1); // sort the array using quick sort
    clock_t quick_end = clock();
    double quick_time_elapsed = (double)(quick_end - quick_start) / CLOCKS_PER_SEC;
    printf("\nSorted array using quick sort:\n");
    print_array(array2, ARRAY_SIZE); // print the sorted array
    printf("Quick sort time: %f seconds\n", quick_time_elapsed);

    return 0;
}