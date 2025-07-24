//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if(num <= 1)
        return false;

    for(int i = 2; i <= num / 2; i++)
        if(num % i == 0)
            return false;

    return true;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    int primes[n], count = 0, i = 2;

    while(count < n) {
        if(isPrime(i)) {
            primes[count] = i;
            count++;
        }
        i++;
    }

    printf("The first %d prime numbers are: ", n);
    for(int j = 0; j < n; j++)
        printf("%d ", primes[j]);

    return 0;
}