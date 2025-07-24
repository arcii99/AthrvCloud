//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>

int isPrime(int num) {
    int i;
    if(num == 2) return 1; // 2 is always a prime number
    if(num % 2 == 0 || num == 1) return 0; // numbers divisible by 2 or 1 are not primes
    for(i = 3; i*i <= num; i+=2) {
        if(num % i == 0) return 0; // if the number is divisible by any odd number other than 1, it is not a prime
    }
    return 1; // the number is prime
}

int main() {
    int n, i = 2, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("%d prime numbers:\n", n);
    while(count < n) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    printf("\n");
    return 0;
}