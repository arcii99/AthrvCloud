//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void perform_task(int* arr) {
    int sum = 0, i;
    for (i = 0; i < SIZE; ++i) {
        // Add each element to the sum
        sum += arr[i];
    }
    printf("Sum of all elements = %d\n", sum);
}

void generate_data(int* arr) {
    int i;
    srand(time(NULL));
    for (i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int arr[SIZE];
    generate_data(arr);

    clock_t start_time = clock();

    perform_task(arr);

    clock_t end_time = clock();
    printf("Time taken = %lf seconds\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}