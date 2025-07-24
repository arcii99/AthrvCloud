//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) { // Function to check if number is prime or not
    if (num < 2) {
        return false;
    }
    for (int i=2; i<=num/2; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, prime_count=0;
    printf("Greetings survivor! Enter the number of prime numbers you want to generate:\n");
    scanf("%d", &n);
    printf("Generating %d prime numbers...\n", n);
    printf("Prime numbers:");
    while (prime_count < n) { // Keep generating prime numbers until we reach the desired amount
        int num = rand() % 1000;
        if (is_prime(num)) {
            printf("%d ", num);
            prime_count++;
        }
    }
    printf("\nStay safe and good luck out there!\n");
    return 0;
}