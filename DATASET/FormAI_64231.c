//FormAI DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

double linear_search(int *array, int size, int key) {
    clock_t start_time = clock();
    for(int i = 0; i < size; i++) {
        if(array[i] == key) {
            return (double)(clock() - start_time) / CLOCKS_PER_SEC;
        }
    }
    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

double binary_search(int *array, int size, int key) {
    int low = 0, high = size - 1;
    clock_t start_time = clock();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(array[mid] < key) {
            low = mid + 1;
        } else if(array[mid] > key) {
            high = mid - 1;
        } else {
            return (double)(clock() - start_time) / CLOCKS_PER_SEC;
        }
    }
    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double quicksort(int *array, int size) {
    clock_t start_time = clock();
    qsort(array, size, sizeof(int), compare);
    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

int main() {
    int array[ARRAY_SIZE];
    int key = rand() % 100;
    srand(time(NULL));
    fill_array(array, ARRAY_SIZE);

    printf("Array size: %d\n", ARRAY_SIZE);
    printf("Key to search for: %d\n\n", key);

    double search_time = linear_search(array, ARRAY_SIZE, key);
    printf("Linear search time: %f seconds\n", search_time);

    search_time = binary_search(array, ARRAY_SIZE, key);
    printf("Binary search time: %f seconds\n", search_time);

    double sort_time = quicksort(array, ARRAY_SIZE);
    printf("Quicksort time: %f seconds\n", sort_time);

    return 0;
}