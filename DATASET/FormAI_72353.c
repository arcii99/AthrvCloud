//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: brave
// Brave C Performance-Critical Component Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the sum of an array of integers
int sum(int *arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

// main function
int main() {
    int size = 1000000;
    int *arr = (int*) malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    int result = sum(arr, size);
    printf("The sum of the array is %d\n", result);
    free(arr);
    return 0;
}