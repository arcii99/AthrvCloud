//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_array(int[], int);
void print_array(int[], int);
void bubble_sort(int[], int);
void selection_sort(int[], int);
void insertion_sort(int[], int);
double benchmark(int[], int, void (*sort_func)(int[], int));

int main() {
    const int ARRAY_SIZE = 10000;

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE], array3[ARRAY_SIZE];
    initialize_array(array1, ARRAY_SIZE);
    initialize_array(array2, ARRAY_SIZE);
    initialize_array(array3, ARRAY_SIZE);

    printf("Bubble sort benchmark: %f seconds\n", benchmark(array1, ARRAY_SIZE, bubble_sort));
    printf("Selection sort benchmark: %f seconds\n", benchmark(array2, ARRAY_SIZE, selection_sort));
    printf("Insertion sort benchmark: %f seconds\n", benchmark(array3, ARRAY_SIZE, insertion_sort));

    return 0;
}

// Fills an array with random integers between 0 and 999
void initialize_array(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}

// Prints the contents of an array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Bubble sort algorithm
void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Selection sort algorithm
void selection_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

// Insertion sort algorithm
void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

// Measures the execution time of a sorting algorithm on an array
double benchmark(int array[], int size, void (*sort_func)(int[], int)) {
    clock_t start = clock();
    (*sort_func)(array, size);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}