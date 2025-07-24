//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function to generate random numbers
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// recursive function that continues to generate random numbers until it finds a prime number.
void findPrimeAsync(int min, int max, void (*callback)()) {
    int n = getRandomInt(min, max);
    bool isPrime = true;
    for (int i=2; i<n; i++) {
        if (n%i == 0) {
            isPrime = false;
            break;
        }
    }
    
    if (isPrime) {
        callback(n); // send result
    } else {
        findPrimeAsync(min, max, callback); // continue searching
    }
}

// callback function that displays the prime number found
void displayResult(int result) {
    printf("The prime number is: %d\n", result);
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // generate random number range
    int min = 100;
    int max = 1000;

    // call recursive function with callback
    findPrimeAsync(min, max, displayResult);

    return 0;
}