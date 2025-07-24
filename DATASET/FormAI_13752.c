//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10000

/* Function to populate the array with random numbers */
void populateArray(int arr[]) {
    srand(time(NULL));  // seed for random number generator
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;  // random number between 0 and ARRAY_SIZE-1
    }
}

/* Function to print the array */
void printArray(int arr[]) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bubble sort on the array */
void bubbleSort(int arr[]) {
    for(int i = 0; i < ARRAY_SIZE-1; i++) {
        for(int j = 0; j < ARRAY_SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                /* swap arr[j] and arr[j+1] */
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    /* Populate the array with random numbers */
    populateArray(arr);

    /* Print the unsorted array */
    printf("Unsorted array: ");
    printArray(arr);

    /* Start the clock */
    start = clock();

    /* Perform bubble sort on the array */
    bubbleSort(arr);

    /* Stop the clock */
    end = clock();

    /* Print the sorted array */
    printf("Sorted array: ");
    printArray(arr);

    /* Calculate the time taken for bubble sort */
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %lf seconds\n", cpu_time_used);

    return 0;
}