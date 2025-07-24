//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100000

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

// Function to generate public and private key
void generate_key(int prime[], int *p, int *q, int *n, int *phi, int *e, int *d) {
    *p = prime[rand() % MAX];
    *q = prime[rand() % MAX];
    while(*p == *q) *q = prime[rand() % MAX];

    *n = (*p) * (*q);
    *phi = (*p - 1) * (*q - 1);
    *e = 2; // Start with smallest possible e
    while(gcd(*e, *phi) != 1) (*e)++;
    // Calculate d using modular multiplicative inverse
    int k = 1;
    while(1) {
        *d = ((*phi) * k + 1) / (*e);
        if((*d) * (*e) == (*phi) * k + 1) break;
        k++;
    }
}

int main() {
    int prime[MAX], cnt = 0;
    // Generate prime numbers using sieve
    int isPrime[MAX];
    for(int i=0;i<MAX;i++) isPrime[i] = 1;
    for(int i=2;i*i<=MAX;i++) {
        if(isPrime[i]) {
            prime[cnt++] = i;
            for(int j=i*i;j<=MAX;j+=i) isPrime[j] = 0;
        }
    }
    for(int i=MAX/2;i<=MAX;i++) {
        if(isPrime[i]) {
            prime[cnt++] = i;
        }
    }

    int p, q, n, phi, e, d;
    generate_key(prime, &p, &q, &n, &phi, &e, &d);

    printf("Public Key \t: (%d, %d)\n", n, e);
    printf("Private Key \t: (%d, %d)\n", n, d);

    return 0;
}