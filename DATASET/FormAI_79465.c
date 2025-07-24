//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 10000000

// function to check if a number is prime
bool is_prime(uint32_t num) {
    if(num < 2)
        return false;
    for(uint32_t i = 2; i*i <= num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    // allocate memory for array
    uint32_t* arr = (uint32_t*) malloc(sizeof(uint32_t) * MAX_SIZE);
    if(arr == NULL) {
        printf("Error: could not allocate memory!");
        return 1;
    }

    // initialize array with primes
    uint32_t num = 2;
    uint32_t index = 0;
    while(index < MAX_SIZE) {
        if(is_prime(num)) {
            arr[index] = num;
            index++;
        }
        num++;
    }

    // calculate sum of all primes in array
    uint64_t sum = 0;
    for(uint32_t i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }

    printf("Sum of first %d primes: %llu", MAX_SIZE, sum);

    // free allocated memory
    free(arr);
    return 0;
}