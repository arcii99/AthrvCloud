//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

// Function to generate random numbers 
void generateRandomNumbers(int numbers[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        numbers[i] = rand() % 1000;
    }
}

// Function to find the sum of all numbers in an array 
int sumOfNumbers(int numbers[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}

int main() {
    int numbers[MAX_NUMBERS];
    generateRandomNumbers(numbers, MAX_NUMBERS);
    clock_t start = clock();
    int sum = sumOfNumbers(numbers, MAX_NUMBERS);
    clock_t end = clock();
    double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum of all numbers: %d\n", sum);
    printf("Time taken: %f seconds\n", timeTaken);
    return 0;
}