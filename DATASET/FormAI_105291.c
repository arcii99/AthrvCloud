//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define SEARCH_VALUE 50000

int find_value(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == SEARCH_VALUE) {
            return i;
        }
    }
    return -1;
}

int main() {
    int i;
    int array[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Fill array with random numbers between 0 and 99999
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100000;
    }

    // Find SEARCH_VALUE
    start = clock();
    int index = find_value(array);
    end = clock();

    // Calculate time taken to find SEARCH_VALUE
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SEARCH_VALUE found at index %d in %f seconds.\n", index, cpu_time_used);

    return 0;
}