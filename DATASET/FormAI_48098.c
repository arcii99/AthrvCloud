//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define LOOP_SIZE 100000

int main() {
    int i, j;
    double start, end, diff;
    int array[ARRAY_SIZE];
    srand(time(NULL));
    
    // Create random array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    
    // Test 1: Calculate sum of array using for loop
    start = clock(); // Start clock
    int sum1 = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum1 += array[i];
    }
    end = clock(); // End clock
    diff = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // Calculate time in milliseconds
    printf("Test 1 took %f ms\n", diff);
    
    // Test 2: Calculate sum of array using while loop
    start = clock();
    int sum2 = 0;
    i = 0;
    while (i < ARRAY_SIZE) {
        sum2 += array[i];
        i++;
    }
    end = clock();
    diff = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Test 2 took %f ms\n", diff);
    
    // Test 3: Calculate sum of array using do-while loop
    start = clock();
    int sum3 = 0;
    i = 0;
    do {
        sum3 += array[i];
        i++;
    } while (i < ARRAY_SIZE);
    end = clock();
    diff = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Test 3 took %f ms\n", diff);
    
    // Test 4: Calculate sum of array using nested loops
    start = clock();
    int sum4 = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < LOOP_SIZE; j++) {
            sum4 += array[i];
        }
    }
    end = clock();
    diff = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Test 4 took %f ms\n", diff);
    
    // Test 5: Calculate sum of array using pointer arithmetic
    start = clock();
    int sum5 = 0;
    int *p = array;
    while (p < array + ARRAY_SIZE) {
        sum5 += *p;
        p++;
    }
    end = clock();
    diff = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Test 5 took %f ms\n", diff);
    
    return 0;
}