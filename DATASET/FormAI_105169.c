//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {43, 78, 65, 12, 43, 90, 10, 32, 67, 98};

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform a bubble sort on a portion of the array
void* bubble_sort(void* arg) {
    int start = *((int*) arg);
    int end = start + ARRAY_SIZE/2;

    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }

    return NULL;
}

int main() {
    // Create two threads to perform bubble sort on both halves of the array
    pthread_t thread1, thread2;
    int start1 = 0;
    int start2 = ARRAY_SIZE/2;
    pthread_create(&thread1, NULL, bubble_sort, &start1);
    pthread_create(&thread2, NULL, bubble_sort, &start2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Combine two sorted halves of the array using merge sort
    int i = 0, j = ARRAY_SIZE/2, k = 0;
    int temp_array[ARRAY_SIZE];
    while (i < ARRAY_SIZE/2 && j < ARRAY_SIZE) {
        if (array[i] < array[j]) {
            temp_array[k++] = array[i++];
        } else {
            temp_array[k++] = array[j++];
        }
    }
    while (i < ARRAY_SIZE/2) {
        temp_array[k++] = array[i++];
    }
    while (j < ARRAY_SIZE) {
        temp_array[k++] = array[j++];
    }

    // Copy temp array back to original array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = temp_array[i];
    }

    // Print sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}