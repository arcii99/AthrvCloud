//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to find the minimum value in an array
int findMin(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to generate random integers to fill the array
void generateRandomIntegers(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

int main() {
    int arr[ARRAY_SIZE];
    generateRandomIntegers(arr, ARRAY_SIZE);

    int min = findMin(arr, ARRAY_SIZE);

    printf("The minimum value in the array is %d\n", min);

    return 0;
}