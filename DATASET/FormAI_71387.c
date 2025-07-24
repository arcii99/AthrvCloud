//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>

#define ARRAY_SIZE 100000 // Size of the array
#define THREADS 4         // Number of threads to use for parallel calculation

int main() {
    int array[ARRAY_SIZE];
    int sum = 0;

    #pragma omp parallel for num_threads(THREADS) reduction(+:sum)
    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(i % 2 == 0) {
            array[i] = i;
        } else {
            array[i] = -i;
        }
        sum += array[i];
    }

    printf("The sum of all elements in the array is: %d\n", sum);

    return 0;
}