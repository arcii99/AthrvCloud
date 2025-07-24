//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // define size of array

// function to print array elements
void print_array(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to generate random numbers between 1 and 100
int get_random_num() {
    return rand() % 100 + 1;
}

int main() {
    int arr[SIZE];
    
    // set seed for random number generator
    srand(time(NULL));
    
    // fill array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = get_random_num();
    }
    
    printf("Unsorted array: ");
    print_array(arr);

    // bubble sort the array
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    print_array(arr);

    return 0;
}