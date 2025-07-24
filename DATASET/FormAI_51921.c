//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    clock_t start, end;
    double cpu_time_used;

    int array[ARRAY_SIZE];
    int i, j, temp;

    // Generate random values for the array
    srand(time(NULL));
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand() % 10000;
    }

    // Bubble sort algorithm
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++) {
        for(j=0; j<ARRAY_SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort completed in %f seconds\n", cpu_time_used);

    // Selection sort algorithm
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++) {
        int min = i;
        for(j=i+1; j<ARRAY_SIZE; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort completed in %f seconds\n", cpu_time_used);

    // Insertion sort algorithm
    start = clock();
    for(i=1; i<ARRAY_SIZE; i++) {
        temp = array[i];
        j = i-1;
        while(j>=0 && array[j]>temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort completed in %f seconds\n", cpu_time_used);

    return 0;
}