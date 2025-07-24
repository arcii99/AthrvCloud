//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include<stdio.h>
#include<math.h>

int checkPrime(int num) {

    if(num < 2) {
        return 0;
    }

    int upperLimit = sqrt(num);
    for(int i=2; i<=upperLimit; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int primeNumbers[200] = {0}; // Array to store prime numbers
    int count = 0, number = 2;   // Initialize count and number

    // Loop to generate prime numbers
    while(count < 200) {
        int isPrime = checkPrime(number);

        if(isPrime == 1) {
            primeNumbers[count] = number; // Store the prime number in the array
            count++;
        }
        number++; // Check next number
    }

    // Print all prime numbers
    printf("List of prime numbers: \n");
    for(int i=0; i<200; i++) {
        printf("%d ", primeNumbers[i]);
    }

    return 0;
}