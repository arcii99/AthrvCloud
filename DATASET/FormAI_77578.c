//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int num_array[ARRAY_SIZE];

void generate_array() {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        num_array[i] = rand();
    }
}

void insertion_sort() {
    int i, j, temp;
    for (i = 1; i < ARRAY_SIZE; i++) {
        temp = num_array[i];
        j = i - 1;
        while (j >= 0 && num_array[j] > temp) {
            num_array[j + 1] = num_array[j];
            j--;
        }
        num_array[j + 1] = temp;
    }
}

void run_benchmark() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertion_sort();
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Insertion Sort with %d elements took %f seconds to execute\n", ARRAY_SIZE, cpu_time_used);
}

int main() {
    generate_array();
    run_benchmark();

    return 0;
}