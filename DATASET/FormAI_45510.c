//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

// This function checks if the given number is prime or not
int isPrime(int num) {
    int i;
    for(i=2;i<=num/2;i++) {
        if(num%i==0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int main() {
    int n, i;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("The prime numbers up to %d are: \n", n);
    for(i=2;i<=n;i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}