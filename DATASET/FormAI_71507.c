//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000 // 10 Million

int main() {
    int i;
    clock_t start, end;
    double cpu_time_used;
    
    int *array = (int *) malloc(sizeof(int) * ARRAY_SIZE);
    if (array == NULL) {
        printf("Error: Failed to allocate memory for the array\n");
        return 1;
    }
    
    // Generate random numbers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }
    
    // Bubble Sort
    start = clock();
    int temp;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Bubble Sort Time: %f seconds\n", cpu_time_used);
    
    // Selection Sort
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Selection Sort Time: %f seconds\n", cpu_time_used);
    
    free(array);
    return 0;
}