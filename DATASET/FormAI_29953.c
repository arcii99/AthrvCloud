//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>

// Function to generate a random prime number
int random_prime() {
    int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int index = rand() % 25;
    return primes[index];
}

// Function to calculate the gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b,a%b);
}

// Function to generate a public key
int generate_public_key(int p, int q) {
    int e = (p-1)*(q-1);
    int i;
    for (i = 2; i < e; i++) {
        if (gcd(i,e) == 1) {
            return i;
        }
    }
    return -1;
}

// Function to calculate the modular inverse
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to generate a private key
int generate_private_key(int p, int q, int e) {
    int n = p*q;
    int phi = (p-1)*(q-1);
    int d = mod_inverse(e,phi);
    return d;
}

int main() {
    int p = random_prime();
    int q = random_prime();
    int e = generate_public_key(p,q);
    int d = generate_private_key(p,q,e);
    
    printf("Public Key: (%d,%d)\n",e,(p*q));
    printf("Private Key: (%d,%d)\n",d,(p*q));
    
    return 0;
}