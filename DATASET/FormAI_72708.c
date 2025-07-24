//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h> 

int isPrime(int n) { 
    // check if n is prime 
    if (n <= 1) return 0; 

    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) return 0; 
    } 
    return 1; 
} 

void generatePrimes(int n) { 
    // generate and print all primes less than or equal to n 
    for (int i = 2; i <= n; i++) { 
        if (isPrime(i)) printf("%d ", i); 
    } 
} 

int main() { 
    int n; 

    printf("Enter a number: "); 
    scanf("%d", &n); 

    printf("The prime numbers less than or equal to %d are: ", n); 
    generatePrimes(n); 
    printf("\n"); 

    return 0; 
}