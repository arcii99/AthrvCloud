//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_VALUE 10000

void generate_numbers(int *array, int size) {
    for(int i=0; i<size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
}

void bubble_sort(int *array, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int *array, int size) {
    for(int i=1; i<size; i++) {
        int key = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

double calculate_time(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int array[ARRAY_SIZE];
    clock_t start, end;
    double time_taken;

    /* Generating random numbers */
    srand(time(NULL));
    generate_numbers(array, ARRAY_SIZE);

    /* Testing Bubble Sort */
    start = clock();
    bubble_sort(array, ARRAY_SIZE);
    end = clock();
    time_taken = calculate_time(start, end);
    printf("Bubble Sort Time: %f\n", time_taken);

    /* Generating random numbers again */
    generate_numbers(array, ARRAY_SIZE);

    /* Testing Insertion Sort */
    start = clock();
    insertion_sort(array, ARRAY_SIZE);
    end = clock();
    time_taken = calculate_time(start, end);
    printf("Insertion Sort Time: %f\n", time_taken);

    return 0;
}