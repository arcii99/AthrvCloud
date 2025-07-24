//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 1 to 100
int randNumGenerator() {
    return rand() % 100 + 1;
}

// Function to calculate the sum of all numbers in an array
int sumArray(int array[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the average of all numbers in an array
float avgArray(int array[], int size) {
    int sum = sumArray(array, size);
    return (float) sum / size;
}

// Main function
int main() {
    srand(time(NULL));
    int size = 1000000; // size of the array
    int array[size];
    for(int i=0; i<size; i++) {
        array[i] = randNumGenerator();
    }

    // Benchmarking the sumArray function
    clock_t start1 = clock();
    int sum = sumArray(array, size);
    clock_t end1 = clock();
    double timeTaken1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
    printf("Sum of array: %d\n", sum);
    printf("Time taken for sumArray function: %f seconds\n", timeTaken1);
    
    // Benchmarking the avgArray function
    clock_t start2 = clock();
    float avg = avgArray(array, size);
    clock_t end2 = clock();
    double timeTaken2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
    printf("Average of array: %f\n", avg);
    printf("Time taken for avgArray function: %f seconds\n", timeTaken2);
    
    return 0;
}