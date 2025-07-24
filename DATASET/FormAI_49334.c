//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num, i;
    bool isPrime;

    printf("Please enter a number to check if it's prime: ");
    scanf("%d", &num);

    // Two is the only even prime number
    if(num == 2) {
        isPrime = true;
    } else if(num < 2 || num%2 == 0) {
        // If number is less than 2 or is even, it's not prime
        isPrime = false;
    } else {
        isPrime = true;
        // Check odd divisors from 3 up to square root of number
        for(i = 3; i*i <= num; i += 2) {
            if(num%i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    // Output the result
    if(isPrime) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    }

    return 0;
}