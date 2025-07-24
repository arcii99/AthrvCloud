//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
// Welcome to the Curious C Data Structures Visualization Program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int elements[MAX_SIZE];
    int count;
} Array;

Array generateRandomArray() {
    Array arr;
    for (int i = 0; i < MAX_SIZE; i++) {
        arr.elements[i] = (rand() % 100) + 1; // set random number between 1 and 100
    }
    arr.count = MAX_SIZE;
    return arr;
}

void printArray(Array arr) {
    printf("[");
    for (int i = 0; i < arr.count; i++) {
        printf(" %d ", arr.elements[i]);
        if (i < arr.count-1) {
            printf("|");
        }
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Array *arr) {
    printf("Applying Bubble Sort Algorithm!\n");
    for (int i = 0; i < arr->count-1; i++) {
        for (int j = 0; j < arr->count-i-1; j++) {
            if (arr->elements[j] > arr->elements[j+1]) {
                swap(&arr->elements[j], &arr->elements[j+1]);
            }
        }
        printArray(*arr); // visualize each step
    }
    printf("Done Sorting!\n");
}

void insertionSort(Array *arr) {
    printf("Applying Insertion Sort Algorithm!\n");
    for (int i = 1; i < arr->count; i++) {
        int key = arr->elements[i];
        int j = i-1;
        while (j >= 0 && arr->elements[j] > key) {
            arr->elements[j+1] = arr->elements[j];
            j = j-1;
        }
        arr->elements[j+1] = key;
        printArray(*arr); // visualize each step
    }
    printf("Done Sorting!\n");
}

void selectionSort(Array *arr) {
    printf("Applying Selection Sort Algorithm!\n");
    for (int i = 0; i < arr->count-1; i++) {
        int min_index = i;
        for (int j = i+1; j < arr->count; j++) {
            if (arr->elements[j] < arr->elements[min_index]) {
                min_index = j;
            }
        }
        swap(&arr->elements[min_index], &arr->elements[i]);
        printArray(*arr); // visualize each step
    }
    printf("Done Sorting!\n");
}

int main() {
    srand(time(NULL)); // seed random number generator
    Array arr = generateRandomArray();
    printf("Original Array: ");
    printArray(arr);
    bubbleSort(&arr);
    printf("\nFinal Array After Bubble Sort: ");
    printArray(arr);
    printf("---------------------------\n");
    arr = generateRandomArray();
    printf("Original Array: ");
    printArray(arr);
    insertionSort(&arr);
    printf("\nFinal Array After Insertion Sort: ");
    printArray(arr);
    printf("---------------------------\n");
    arr = generateRandomArray();
    printf("Original Array: ");
    printArray(arr);
    selectionSort(&arr);
    printf("\nFinal Array After Selection Sort: ");
    printArray(arr);
    return 0;
}