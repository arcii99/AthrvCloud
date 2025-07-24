//FormAI DATASET v1.0 Category: Benchmarking ; Style: shape shifting
// Shape-shifting Benchmarking Program - By Chatbot

#include <stdio.h>
#include <time.h>

// Define the size of the array
#define ARRAY_SIZE 10000

// Declare the arrays that will be used for benchmarking
int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE], arr3[ARRAY_SIZE];

// Define a function that will be used for swapping the values of two variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i, j;

    // Generate a random array with integers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr1[i] = rand() % ARRAY_SIZE;
    }

    // Time the execution of Bubble Sort algorithm
    clock_t start_bubble = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr1[j] > arr1[j+1]) {
                swap(&arr1[j], &arr1[j+1]);
            }
        }
    }
    clock_t end_bubble = clock();
    double time_bubble = (double) (end_bubble - start_bubble) / CLOCKS_PER_SEC;

    // Time the execution of Selection Sort algorithm
    clock_t start_selection = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr1[j] < arr1[min_index]) {
                min_index = j;
            }
        }
        swap(&arr1[min_index], &arr1[i]);
    }
    clock_t end_selection = clock();
    double time_selection = (double) (end_selection - start_selection) / CLOCKS_PER_SEC;

    // Time the execution of Insertion Sort algorithm
    clock_t start_insertion = clock();
    for (i = 1; i < ARRAY_SIZE; i++) {
        int key = arr1[i];
        j = i - 1;
        while (j >= 0 && arr1[j] > key) {
            arr1[j+1] = arr1[j];
            j--;
        }
        arr1[j+1] = key;
    }
    clock_t end_insertion = clock();
    double time_insertion = (double) (end_insertion - start_insertion) / CLOCKS_PER_SEC;

    // Print the execution times of the algorithms
    printf("Execution time of Bubble Sort: %.6f seconds\n", time_bubble);
    printf("Execution time of Selection Sort: %.6f seconds\n", time_selection);
    printf("Execution time of Insertion Sort: %.6f seconds\n", time_insertion);

    return 0;
}