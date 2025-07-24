//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeGenerator(int n) {
    int count = 0;
    int i = 2;
    printf("The first %d prime numbers are:\n", n);
    while(count < n) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    primeGenerator(n);
    return 0;
}