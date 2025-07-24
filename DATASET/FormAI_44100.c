//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREADS 4 // Number of threads to create
#define ARRAY_SIZE 1000000 // Size of the array to be sorted

int array[ARRAY_SIZE]; // Unsorted array
int sorted[ARRAY_SIZE]; // Array to store sorted elements

// Function to perform Quick Sort
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    // Partition array
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Recursive calls to sort left and right sub-arrays
    if (left < j) {
        quick_sort(arr, left, j);
    }
    if (i < right) {
        quick_sort(arr, i, right);
    }
}

// Function to sort array in multiple threads
void *thread_sort(void *arg) {
    int thread_num = *(int *)arg;
    int start = thread_num * (ARRAY_SIZE / THREADS);
    int end = ((thread_num + 1) * (ARRAY_SIZE / THREADS)) - 1;
    printf("Thread %d sorting elements from %d to %d\n", thread_num + 1, start, end);
    quick_sort(array, start, end);
    return NULL;
}

int main() {
    srand(time(NULL));
    // Initialize unsorted array with random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Create threads and sort array
    pthread_t threads[THREADS];
    for (int i = 0; i < THREADS; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, thread_sort, (void *)thread_num);
    }

    // Wait for threads to join
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge sub-arrays into sorted array
    int sub_size = ARRAY_SIZE / THREADS;
    int indices[THREADS] = { 0 };
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int smallest_index = -1;
        int smallest_value;
        for (int j = 0; j < THREADS; j++) {
            if (indices[j] < sub_size && (smallest_index == -1 || array[j * sub_size + indices[j]] < smallest_value)) {
                smallest_index = j;
                smallest_value = array[j * sub_size + indices[j]];
            }
        }
        sorted[i] = smallest_value;
        indices[smallest_index]++;
    }

    // Print sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    return 0;
}