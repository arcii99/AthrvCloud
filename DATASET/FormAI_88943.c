//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100     // Maximum number in random array
#define ARRAY_SIZE 10   // Size of random array

int generateRandomArray(int array[], int size);
void displayArray(int array[], int size);

int main() {
    int randomNumbers[ARRAY_SIZE];
    
    generateRandomArray(randomNumbers, ARRAY_SIZE);
    displayArray(randomNumbers, ARRAY_SIZE);
    
    return 0;
}

/**
 * Generates an array of random integers.
 * 
 * @param array - Array of integers to fill with random numbers.
 * @param size - Number of integers to generate for the array.
 */
int generateRandomArray(int array[], int size) {
    int i;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate random numbers for each element in the array
    for (i = 0; i < size; i++) {
        array[i] = rand() % MAX_NUM;
    }
    
    return 0;
}

/**
 * Displays the contents of an array.
 * 
 * @param array - Array of integers to display.
 * @param size - Number of integers in the array.
 */
void displayArray(int array[], int size) {
    int i;
    
    printf("Random Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}