//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

// Function to check if num is prime
bool isPrime(int num) {

    if (num < 2) {
        return false;
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
    }

    return true;
}

// Function to generate the next prime number
int nextPrime(int currentPrime) {

    int next = currentPrime + 1;

    while (!isPrime(next)) {
        next++;
    }

    return next;

}

int main() {

    int currentPrime = 2;

    printf("The first prime number is: %d\n", currentPrime);

    for (int i = 0; i < 20; i++) {

        currentPrime = nextPrime(currentPrime);

        printf("The next prime number is: %d\n", currentPrime);

    }

    return 0;

}