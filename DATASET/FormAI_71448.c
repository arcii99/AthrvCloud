//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(int argc, char** argv) {
    clock_t start, end;
    double total_time;
    int i;
    int array[ARRAY_SIZE];

    //randomly populate the array
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    //benchmarking bubble sort
    start = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++) {
        for(int j = 0; j < ARRAY_SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %lf seconds\n", total_time);

    //benchmarking quick sort
    start = clock();
    quickSort(array, 0, ARRAY_SIZE-1);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick sort time: %lf seconds\n", total_time);

    return 0;
}

void quickSort(int *array, int low, int high) {
    if(low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return i+1;
}