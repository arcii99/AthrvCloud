//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// modular code for generating a cryptographic hash value using prime numbers

// function that calculates the hash value
unsigned long long hash(char *str) {
    // setting up the prime number array
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    // initialize the hash value
    unsigned long long hashVal = 0;
    
    // iterate through the characters in the input string
    for (int i = 0; i < strlen(str); i++) {
        // add the ascii value of the character multiplied by the corresponding prime number
        hashVal += str[i] * primes[i % 10];
    }
    
    // return the final hash value
    return hashVal;
}

// main function to test the hash function
int main() {
    // input string
    char *input = "hello world";
    
    // calculate the hash value
    unsigned long long result = hash(input);
    
    // print the result
    printf("Hash value of '%s' is %llu\n", input, result);
    
    return 0;
}