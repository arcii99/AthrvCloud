//FormAI DATASET v1.0 Category: Benchmarking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random array of integers 
void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
}

// function to print array of integers
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to implement bubble sort algorithm
void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// function to implement insertion sort algorithm
void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

int main() {
    // define array size
    int size = 10000;
    
    // generate random array
    int array[size];
    generate_random_array(array, size);
    
    // measure time for bubble sort algorithm
    clock_t start = clock();
    bubble_sort(array, size);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %f seconds\n", time_taken);

    // generate random array again
    generate_random_array(array, size);

    // measure time for insertion sort algorithm
    start = clock();
    insertion_sort(array, size);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for insertion sort: %f seconds\n", time_taken);

    return 0;
}