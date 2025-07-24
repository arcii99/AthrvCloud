//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

int isPrime(int num) {  // Function to determine if a number is prime
    int i;
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return 0;  // Not prime
        }
    }
    return 1;  // Prime
}

int main() {
    int n, i, count = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);

    for(i = 2;; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        if(count == n) {  // When we have printed n prime numbers, break out of the loop
            break;
        }
    }

    return 0;
}