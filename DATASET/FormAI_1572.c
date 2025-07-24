//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int my_array[ARRAY_SIZE];
    int i, j;
    clock_t start, end;
    double cpu_time_used;

    // initialize the array with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        my_array[i] = rand();
    }

    // sort the array using bubble sort
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (my_array[j] > my_array[j + 1]) {
                int temp = my_array[j];
                my_array[j] = my_array[j + 1];
                my_array[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array in %f seconds\n", cpu_time_used);

    return 0;
}