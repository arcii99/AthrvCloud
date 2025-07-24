//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include<stdio.h>
#include<math.h>

int isPrime(int num) {
    int i, sqrt_num;
    if (num ==2 || num == 3)
        return 1;
    if (num % 2 == 0 || num == 1)
        return 0;
    sqrt_num = sqrt(num);
    for (i = 3; i <= sqrt_num; i += 2)
        if (num % i == 0)
            return 0;
    return 1;
}

void main() {
    int n, prime_count = 0, num = 2;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d",&n);
    printf("Generating %d primes:\n", n);
    while (prime_count < n) {
        if(isPrime(num)) {
            printf("%d ", num);
            prime_count++;
        }
        num++;
    }
}