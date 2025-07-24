//FormAI DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ARRAY_SIZE 1000000
#define BENCHMARK_ITERATIONS 100000

// function to generate a random number between 0 and 999
int generateRandomNumber() {
    return rand() % 1000;
}

// function to populate an array with random numbers
void populateArrayWithRandomNumbers(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = generateRandomNumber();
    }
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize array
    int array[ARRAY_SIZE];

    // generate random numbers and populate array
    populateArrayWithRandomNumbers(array);

    // perform benchmarking for linear search
    clock_t linearSearchStart = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        int targetIndex = -1;
        int target = generateRandomNumber();
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (array[j] == target) {
                targetIndex = j;
                break;
            }
        }
    }
    clock_t linearSearchEnd = clock();
    double linearSearchTime = ((double) (linearSearchEnd - linearSearchStart)) / CLOCKS_PER_SEC;

    // perform benchmarking for binary search
    clock_t binarySearchStart = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        int targetIndex = -1;
        int target = generateRandomNumber();
        int low = 0;
        int high = ARRAY_SIZE - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (array[mid] == target) {
                targetIndex = mid;
                break;
            } else if (array[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    clock_t binarySearchEnd = clock();
    double binarySearchTime = ((double) (binarySearchEnd - binarySearchStart)) / CLOCKS_PER_SEC;

    // output performance results
    printf("Linear search took %f seconds\n", linearSearchTime);
    printf("Binary search took %f seconds\n", binarySearchTime);

    return 0;
}