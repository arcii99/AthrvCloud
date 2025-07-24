//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int gcd(long int a, long int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long int modexp(long int base, long int exponent, long int modulus) {
    long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int millerRabinTest(long int n, int k) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }

    long int d = n - 1;
    int s = 0;
    while (d % 2 == 0)  {
        s++;
        d /= 2;
    }

    srand(time(NULL));
    for (int i = 0; i < k; i++) {
        long int a = (rand() % (n - 1)) + 1;
        long int x = modexp(a, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }
        int j;
        for (j = 0; j < s - 1; j++) {
            x = modexp(x, 2, n);
            if (x == 1) {
                return 0;
            }
            if (x == n - 1) {
                break;
            }
        }
        if (j == s - 1) {
            return 0;
        }
    }
    return 1;
}

long int generatePrime(int n) {
    long int prime = (rand() % (1 << n)) + (1 << (n - 1));
    while (1) {
        if (millerRabinTest(prime, 10)) {
            return prime;
        } else {
            prime++;
        }
    }
}

long int generatePrivateKey(long int p, long int q, long int e) {
    long int phi = (p - 1) * (q - 1);
    long int d;
    for (d = 3; d < phi; d++) {
        if (gcd(e, phi) == 1 && (e * d) % phi == 1) {
            return d;
        }
    }
    return -1;
}

int main() {
    long int p = generatePrime(10);
    long int q = generatePrime(10);
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);
    
    long int e = 3;
    while (gcd(e, phi) != 1) {
        e += 2;
    }
    
    long int d = generatePrivateKey(p, q, e);

    printf("Public Key: (%ld, %ld)\n", e, n);
    printf("Private Key: (%ld, %ld)\n", d, n);

    return 0;
}