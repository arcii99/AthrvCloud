//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the struct to hold the public and private keys
struct RSA_Key {
    int p, q, n, t, e, d;
};

// Define a function to find the greatest common divisor
int gcd(int a, int b) {
    int temp;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Define a function to determine if a number is prime
int isPrime(int num) {
    int i;
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Define a function to generate the RSA keys
struct RSA_Key generate_keys() {
    struct RSA_Key rsa_key;
    int p, q, n, t, e = 2, d;
    do {
        p = rand() % 100 + 1;
    } while(!isPrime(p));
    do {
        q = rand() % 100 + 1;
    } while(!isPrime(q) || q == p);
    n = p * q;
    t = (p - 1) * (q - 1);
    while(e < t) {
        if(gcd(e, t) == 1) {
            break;
        } else {
            e++;
        }
    }
    int k = 2;
    d = (1 + (k * t)) / e;
    rsa_key.p = p;
    rsa_key.q = q;
    rsa_key.n = n;
    rsa_key.t = t;
    rsa_key.e = e;
    rsa_key.d = d;
    return rsa_key;
}

int main() {
    struct RSA_Key rsa_key = generate_keys();

    printf("Public Key: (%d, %d)\n", rsa_key.n, rsa_key.e);
    printf("Private Key: (%d, %d)\n", rsa_key.n, rsa_key.d);

    return 0;
}