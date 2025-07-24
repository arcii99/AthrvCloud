//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void bubble_sort(int array[], int size);
void insertion_sort(int array[], int size);
void selection_sort(int array[], int size);
void quick_sort(int array[], int left, int right);
void merge_sort(int array[], int left, int right);
void heap_sort(int array[], int size);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Define array sizes to test
    int sizes[] = {1000, 10000, 100000};
    
    // Define number of runs for benchmarking
    int num_runs = 5;
    
    // Iterate over array sizes
    for (int i = 0; i < sizeof(sizes)/sizeof(int); i++) {
        int size = sizes[i];
        printf("Performance benchmarking for array size %d\n", size);
        
        // Initialize array
        int array[size];
        // Fill array with random integers
        for (int j = 0; j < size; j++) {
            array[j] = rand() % size;
        }
        
        // Bubble sort benchmark
        clock_t start = clock();
        for (int j = 0; j < num_runs; j++) {
            bubble_sort(array, size);
        }
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Bubble sort: %.4f seconds\n", elapsed/num_runs);
        
        // Insertion sort benchmark
        start = clock();
        for (int j = 0; j < num_runs; j++) {
            insertion_sort(array, size);
        }
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Insertion sort: %.4f seconds\n", elapsed/num_runs);
        
        // Selection sort benchmark
        start = clock();
        for (int j = 0; j < num_runs; j++) {
            selection_sort(array, size);
        }
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Selection sort: %.4f seconds\n", elapsed/num_runs);
        
        // Quick sort benchmark
        start = clock();
        for (int j = 0; j < num_runs; j++) {
            quick_sort(array, 0, size-1);
        }
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Quick sort: %.4f seconds\n", elapsed/num_runs);
        
        // Merge sort benchmark
        start = clock();
        for (int j = 0; j < num_runs; j++) {
            merge_sort(array, 0, size-1);
        }
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Merge sort: %.4f seconds\n", elapsed/num_runs);
        
        // Heap sort benchmark
        start = clock();
        for (int j = 0; j < num_runs; j++) {
            heap_sort(array, size);
        }
        end = clock();
        elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Heap sort: %.4f seconds\n", elapsed/num_runs);
    }
    
    return 0;
}

/**
 * Bubble sort algorithm
 */
void bubble_sort(int array[], int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/**
 * Insertion sort algorithm
 */
void insertion_sort(int array[], int size) {
    int key = 0;
    int j = 0;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

/**
 * Selection sort algorithm
 */
void selection_sort(int array[], int size) {
    int min_index = 0;
    int temp = 0;
    for (int i = 0; i < size-1; i++) {
        min_index = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

/**
 * Quick sort algorithm
 */
void quick_sort(int array[], int left, int right) {
    if (left < right) {
        int pivot = array[right];
        int i = left-1;
        int temp = 0;
        for (int j = left; j < right; j++) {
            if (array[j] < pivot) {
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[i+1];
        array[i+1] = array[right];
        array[right] = temp;
        
        quick_sort(array, left, i);
        quick_sort(array, i+2, right);
    }
}

/**
 * Merge sort algorithm
 */
void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
        
        int left_size = mid-left+1;
        int right_size = right-mid;
        
        int left_array[left_size];
        int right_array[right_size];
        
        for (int i = 0; i < left_size; i++) {
            left_array[i] = array[left+i];
        }
        for (int i = 0; i < right_size; i++) {
            right_array[i] = array[mid+1+i];
        }
        
        int left_index = 0;
        int right_index = 0;
        int merged_index = left;
        
        while (left_index < left_size && right_index < right_size) {
            if (left_array[left_index] <= right_array[right_index]) {
                array[merged_index] = left_array[left_index];
                left_index++;
            } else {
                array[merged_index] = right_array[right_index];
                right_index++;
            }
            merged_index++;
        }
        
        while (left_index < left_size) {
            array[merged_index] = left_array[left_index];
            left_index++;
            merged_index++;
        }
        
        while (right_index < right_size) {
            array[merged_index] = right_array[right_index];
            right_index++;
            merged_index++;
        }
    }
}

/**
 * Heap sort algorithm
 */
void heap_sort(int array[], int size) {
    for (int i = size/2-1; i >= 0; i--) {
        heapify(array, size, i);
    }
    
    for (int i = size-1; i >= 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        
        heapify(array, i, 0);
    }
}

/**
 * Heapify algorithm (used for heap sort)
 */
void heapify(int array[], int size, int root) {
    int max = root;
    int left = 2*root+1;
    int right = 2*root+2;
    
    if (left < size && array[left] > array[max]) {
        max = left;
    }
    if (right < size && array[right] > array[max]) {
        max = right;
    }
    
    if (max != root) {
        int temp = array[root];
        array[root] = array[max];
        array[max] = temp;
        
        heapify(array, size, max);
    }
}