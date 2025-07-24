//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int* num_array = NULL; // initialize the pointer to NULL
    int array_size = rand() % 100 + 1; // generate a random array size between 1 and 100
    
    num_array = (int*) malloc(array_size * sizeof(int)); // allocate memory for the array
    
    if(num_array == NULL) { // if memory allocation failed
        printf("Memory allocation failed\n");
        return 1;
    }
    
    int sum = 0;
    for(int i = 0; i < array_size; i++) {
        num_array[i] = rand() % 100; // fill the array with random numbers between 0 and 99
        sum += num_array[i]; // add each number to the sum
    }
    
    printf("Array Size: %d\n", array_size);
    printf("Numbers in Array: ");
    for(int i = 0; i < array_size; i++) {
        printf("%d ", num_array[i]); // print the numbers in the array
    }
    printf("\n");
    
    printf("Sum of Numbers: %d\n", sum);
    
    free(num_array); // free the allocated memory
    
    return 0;
}