//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int array[]) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }
}

void print_array(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", array[i]);
    }
}

void bubble_sort(int array[]) {
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[ARRAY_SIZE];
    fill_array(array);
    clock_t start_time, end_time;
    double time_taken;

    // Benchmark Bubble Sort
    start_time = clock();
    bubble_sort(array);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds.\n", time_taken);

    return 0;
}