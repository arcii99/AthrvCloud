//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {
    int* arr = (int*)malloc(SIZE * sizeof(int));
    srand(time(0));
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }
    long long sum = 0;
    clock_t start = clock();
    for(int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    clock_t end = clock();
    printf("Sum = %lld\n", sum);
    printf("Time taken: %f seconds\n",((double)end - start) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}