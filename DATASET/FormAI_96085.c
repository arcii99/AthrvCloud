//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#define ARRAY_SIZE 1000000 // define the size of array

int main() {
    long long sum = 0; // initialize sum variable
    int numbers[ARRAY_SIZE]; // declare array of integers
    
    // populate the array with numbers from 1 to ARRAY_SIZE
    for(int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = i + 1;
    }
    
    // loop through the array and calculate the sum
    for(int i = 0; i < ARRAY_SIZE; i++) {
        sum += numbers[i];
    }
    
    printf("The sum of numbers from 1 to %d is %lld\n", ARRAY_SIZE, sum); // print the sum
    
    return 0;
}