//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4   // Define the number of threads to be used
#define ARRAY_SIZE 1000 // Define the size of the array to be sorted
#define MAX_NUMBER 100  // Define the maximum number that the array can consist of

int array[ARRAY_SIZE];  // Define the array

// Function to generate an array of random integers
void generate_array() {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % MAX_NUMBER;
    }
}

// Function to print the array
void print_array() {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to swap two elements of the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort algorithm
void bubble_sort(int start, int end) {
    for(int i = start; i < end; i++) {
        for(int j = 0; j < ARRAY_SIZE-1-i; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main() {
    generate_array();   // Generate random array

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS][2];

    // Divide the array into multiple portions and sort each portion in parallel
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_args[i][0] = i * (ARRAY_SIZE/NUM_THREADS); // Starting index for the thread
        thread_args[i][1] = (i+1) * (ARRAY_SIZE/NUM_THREADS); // Ending index for the thread

        pthread_create(&threads[i], NULL, (void*)bubble_sort, (void*)thread_args[i]);
    }

    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted portions of the array
    for(int i = 0; i < NUM_THREADS-1; i++) {
        int start = thread_args[i][0];
        int end = thread_args[i][1];
        int mid = (start + end) / 2;

        int left = start;
        int right = mid+1;

        int temp[ARRAY_SIZE];
        int index = start;

        while(left <= mid && right <= end) {
            if(array[left] < array[right]) {
                temp[index] = array[left];
                left++;
            }
            else {
                temp[index] = array[right];
                right++;
            }
            index++;
        }

        // Copy the remaining elements left in the left side of the array
        while(left <= mid) {
            temp[index] = array[left];
            left++;
            index++;
        }

        // Copy the remaining elements left in the right side of the array
        while(right <= end) {
            temp[index] = array[right];
            right++;
            index++;
        }

        // Copy the merged and sorted portion back to the original array
        for(int j = start; j <= end; j++) {
            array[j] = temp[j];
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    print_array();

    return 0;
}