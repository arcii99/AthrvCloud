//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

// Generate random number between 0 and 99999
int random_number() {
    return rand() % 100000;
}

// Calculate sum of array using a loop
int loop_sum(int *array) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    return sum;
}

// Calculate sum of array using recursion
int recursive_sum(int *array, int index) {
    if (index == ARRAY_SIZE - 1) {
        return array[index];
    } else {
        return array[index] + recursive_sum(array, index+1);
    }
}

int main() {
    int array[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Populate the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = random_number();
    }

    // Calculate the sum of array using a loop
    start = clock();
    int loop_sum_result = loop_sum(array);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Loop sum: %d\n", loop_sum_result);
    printf("Time used for loop sum: %f seconds\n\n", cpu_time_used);

    // Calculate the sum of array using recursion
    start = clock();
    int recursive_sum_result = recursive_sum(array, 0);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive sum: %d\n", recursive_sum_result);
    printf("Time used for recursive sum: %f seconds\n\n", cpu_time_used);

    return 0;
}