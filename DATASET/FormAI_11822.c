//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Fill the array with random numbers
void fill_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

// Print the array
void print_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble sort algorithm
void bubble_sort(int *arr) {
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE];
    fill_array(arr1);
    fill_array(arr2);
    
    clock_t start_bubble = clock();
    bubble_sort(arr1);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort: %lf seconds\n", time_bubble);
    
    clock_t start_insertion = clock();
    // Insertion sort algorithm
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr2[i];
        int j = i - 1;
        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j--;
        }
        arr2[j + 1] = key;
    }
    clock_t end_insertion = clock();
    double time_insertion = ((double) (end_insertion - start_insertion)) / CLOCKS_PER_SEC;
    printf("Time taken by Insertion Sort: %lf seconds\n", time_insertion);
    
    // Uncomment below line to print sorted arrays
    // print_array(arr1);
    // print_array(arr2);

    return 0;
}