//FormAI DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

void fill_array(int array[]) {
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        array[i] = rand();
    }
}

void bubble_sort(int array[]) {
    int temp;
    for (int i = 0; i < ARR_SIZE - 1; i++) {
        for (int j = 0; j < ARR_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[ARR_SIZE];
    fill_array(array);

    clock_t start = clock();
    bubble_sort(array);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting time: %f seconds\n", cpu_time_used);

    return 0;
}