//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the prime number generator function
int generate_prime() {
    int prime, flag;
    do {
        prime = rand() % 100 + 1; // Generate a number between 1 and 100
        flag = 0;
        for(int i=2; i*i <= prime; i++) {
            if(prime % i == 0) {
                flag = 1;
                break;
            }
        }
    } while(flag == 1); // Keep generating until a prime number is found
    return prime;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate two prime numbers p and q
    int p = generate_prime();
    int q = generate_prime();

    // Calculate n = p * q
    int n = p * q;

    // Calculate Euler's Totient function of n
    int totient_n = (p - 1) * (q - 1);

    // Find a number e such that 1 < e < totient_n and gcd(e, totient_n) = 1
    int e;
    for(int i=2; i<totient_n; i++) {
        if(totient_n % i != 0) { // i is a factor of totient_n
            e = i;
            break;
        }
    }

    // Find the multiplicative inverse d of e such that d * e = 1 (mod totient_n)
    int d;
    for(int i=1; i<totient_n; i++) {
        if((i * e) % totient_n == 1) {
            d = i;
            break;
        }
    }

    // Print the public key (n, e) and the private key (n, d)
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    return 0;
}