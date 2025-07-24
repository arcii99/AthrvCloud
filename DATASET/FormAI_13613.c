//FormAI DATASET v1.0 Category: Sorting ; Style: curious
/* Welcome to the curious world of sorting! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* We need a function to randomly shuffle the array */
void shuffle(int *arr, int size) {
    int i, j, temp;
    for (i = size - 1; i > 0; i--) {
        j = rand() % i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* Let's create a function to print the array */
void print_array(int *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/* Here's the curious sorting function */
void curious_sort(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                /* Swap adjacent elements if they are in the wrong order */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                /* Now let's shuffle the remaining elements */
                shuffle(&arr[j+2], size-j-2);
                /* And print the current state of the array */
                printf("Current state of the array after sorting pass %d:\n", i+1);
                print_array(arr, size);
            }
        }
    }
}

/* Main function to test the curious sort */
int main() {
    printf("Welcome to the curious world of sorting!\n");
    srand(time(0)); /* Seed the random number generator */
    int size = 10;
    int arr[] = {5, 1, 9, 3, 7, 2, 8, 4, 6, 0};
    printf("Original array:\n");
    print_array(arr, size);
    curious_sort(arr, size);
    printf("Final sorted array:\n");
    print_array(arr, size);
    return 0;
}