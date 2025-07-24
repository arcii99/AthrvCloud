//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, int size) {
    int i;
    for(i=0; i<size; i++) {
        array[i] = rand() % 1000;
    }
}

void bubble_sort(int *array, int size) {
    int i,j,tmp;
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-1-i; j++) {
            if(array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

int binary_search(int *array, int size, int key) {
    int low = 0, high = size-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(key == array[mid]) {
            return mid;
        } else if(key < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int array[ARRAY_SIZE];
    int key, index;
    clock_t start, end;
    double cpu_time_used;

    fill_array(array, ARRAY_SIZE);

    // Bubble sort
    start = clock();
    bubble_sort(array, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f seconds\n", cpu_time_used);

    // Binary search
    key = array[rand() % ARRAY_SIZE];
    start = clock();
    index = binary_search(array, ARRAY_SIZE, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary search time: %f seconds\n", cpu_time_used);
    if(index == -1) {
        printf("Key %d not found in array\n", key);
    } else {
        printf("Key %d found at index %d\n", key, index);
    }

    return 0;
}