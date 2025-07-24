//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// A function to generate a random array of integers
void generate_random_array(int* array) {
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }
}

// A function to print an array of integers
void print_array(int* array) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// A function to benchmark the bubble sort algorithm
double bubble_sort(int* array) {
    clock_t start = clock();

    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    clock_t end = clock();
    double time_taken = ((double) end - start) / CLOCKS_PER_SEC;
    return time_taken;   
}

// A function to benchmark the quicksort algorithm
void quicksort(int* array, int left, int right) {
    if(left >= right) {
        return;
    }

    int pivot = array[right];
    int i = left;
    int j = right - 1;
    int temp;

    while(i <= j) {
        while(array[i] <= pivot && i <= j) {
            i++;
        }
        while(array[j] >= pivot && i <= j) {
            j--;
        }
        if(i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[i];
    array[i] = array[right];
    array[right] = temp;

    quicksort(array, left, i-1);
    quicksort(array, i+1, right);
}

double benchmark_quicksort(int* array) {
    clock_t start = clock();

    quicksort(array, 0, ARRAY_SIZE-1);

    clock_t end = clock();
    double time_taken = ((double) end - start) / CLOCKS_PER_SEC;
    return time_taken;
}

// A function to benchmark the merge sort algorithm
void merge(int* array, int low, int mid, int high) {
    int i, j, k;
    int temp[ARRAY_SIZE];

    i = low;
    k = 0;
    j = mid + 1;

    while(i <= mid && j <= high) {
        if(array[i] < array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = array[i++];
    }

    while(j <= high) {
        temp[k++] = array[j++];
    }

    for(i = low; i <= high; i++) {
        array[i] = temp[i-low];
    }
}

void mergesort(int* array, int low, int high) {
    int mid;

    if(low < high) {
        mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid+1, high);
        merge(array, low, mid, high);
    }
}

double benchmark_mergesort(int* array) {
    clock_t start = clock();

    mergesort(array, 0, ARRAY_SIZE-1);

    clock_t end = clock();
    double time_taken = ((double) end - start) / CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    int array[ARRAY_SIZE];

    printf("Generating random integer array of size %d...\n", ARRAY_SIZE);
    generate_random_array(array);

    printf("Original array: ");
    print_array(array);

    printf("\nRunning bubble sort algorithm...\n");
    double bubble_sort_time = bubble_sort(array);
    printf("Sorted array: ");
    print_array(array);
    printf("Time taken by bubble sort: %f seconds.\n", bubble_sort_time);

    printf("\nRunning quicksort algorithm...\n");
    generate_random_array(array);
    double quicksort_time = benchmark_quicksort(array);
    printf("Sorted array: ");
    print_array(array);
    printf("Time taken by quicksort: %f seconds.\n", quicksort_time);

    printf("\nRunning merge sort algorithm...\n");
    generate_random_array(array);
    double mergesort_time = benchmark_mergesort(array);
    printf("Sorted array: ");
    print_array(array);
    printf("Time taken by merge sort: %f seconds.\n", mergesort_time);

    printf("\nBenchmarking completed successfully!\n");
    return 0;
}