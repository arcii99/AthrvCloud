//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10 // define size of array

// function prototypes
void generate_array(int array[]);
void print_array(int array[]);
void selection_sort(int array[]);
void bubble_sort(int array[]);
void insertion_sort(int array[]);
void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main() {
    int array[ARRAY_SIZE];
    
    // generate array
    generate_array(array);
    
    printf("Original Array:\n");
    print_array(array);

    printf("\nAfter Selection Sort:\n");
    selection_sort(array);
    print_array(array);

    printf("\nAfter Bubble Sort:\n");
    bubble_sort(array);
    print_array(array);

    printf("\nAfter Insertion Sort:\n");
    insertion_sort(array);
    print_array(array);

    printf("\nAfter Quick Sort:\n");
    quick_sort(array, 0, ARRAY_SIZE - 1);
    print_array(array);

    return 0;
}

// function to generate random numbers between 0 and 100 and store them in the array
void generate_array(int array[]) {
    int i;

    srand(time(NULL)); // seed random number generator

    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}

// function to print the array
void print_array(int array[]) {
    int i;

    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

// function to perform selection sort on the array
void selection_sort(int array[]) {
    int i, j, min;
    int temp;

    for(i = 0; i < ARRAY_SIZE - 1; i++) {
        min = i;
        for(j = i + 1; j < ARRAY_SIZE; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }

        if(min != i) {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

// function to perform bubble sort on the array
void bubble_sort(int array[]) {
    int i, j;
    int temp;

    for(i = 0; i < ARRAY_SIZE - 1; i++) {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// function to perform insertion sort on the array
void insertion_sort(int array[]) {
    int i, j;
    int key;

    for(i = 1; i < ARRAY_SIZE; i++) {
        key = array[i];

        for(j = i - 1; j >= 0 && array[j] > key; j--) {
            array[j+1] = array[j];
        }

        array[j+1] = key;
    }
}

// function to perform quick sort on the array
void quick_sort(int array[], int start, int end) {
    if(start < end) {
        int pivot = partition(array, start, end);
        quick_sort(array, start, pivot - 1);
        quick_sort(array, pivot + 1, end);
    }
}

// function to partition the array for quick sort
int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = start - 1;
    int temp;

    for(int j = start; j <= end - 1; j++) {
        if(array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[i+1];
    array[i+1] = array[end];
    array[end] = temp;

    return i+1;
}