//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    // special cases
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    // check if n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // check all the numbers of the form 6k+-1 up to sqrt(n)
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

void generatePrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    
    printf("The prime numbers up to %d are:\n", n);
    generatePrimes(n);
    
    return 0;
}