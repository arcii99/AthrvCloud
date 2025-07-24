//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int isPrime(int n) {
    // Base cases
    if (n <= 1) return 0;
    if (n <= 3) return 1;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return 0;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return 0;
 
    return 1;
}
 
void generatePrimes(int n) {
    printf("Generating primes up to %d:\n", n);
    for(int i=2;i<=n;i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
 
int main()  {
    int n;
    printf("Enter maximum number to search for primes: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}