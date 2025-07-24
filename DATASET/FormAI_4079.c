//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void fillArray(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

int findMaxElement(int *arr) {
    int max = arr[0];
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    srand(time(NULL));
    int arr[ARRAY_SIZE];
    fillArray(arr);
    
    clock_t start = clock();
    int max = findMaxElement(arr);
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The maximum element in the array is: %d\n", max);
    printf("The program took %f seconds to run.\n", time_spent);
    
    return 0;
}