//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){
    /* This function takes an integer n as input and returns
    a boolean value indicating whether the number is prime or not. */
    if (n < 2) {
        return false;
    } else {
        for (int i=2; i*i<=n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}

void prime_generator(int lower, int upper){
    /* This function takes two integers lower and upper as input
    and prints all the prime numbers between them (inclusive). */
    printf("The prime numbers between %d and %d are:\n", lower, upper);
    for (int i=lower; i<=upper; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    // Test the prime_generator function
    prime_generator(1, 10); // Expected output: 2 3 5 7
    prime_generator(20, 30); // Expected output: 23 29
    prime_generator(50, 70); // Expected output: 53 59 61 67
    return 0;
}