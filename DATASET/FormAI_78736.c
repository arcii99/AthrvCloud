//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long power(unsigned long long base, unsigned long long exp, unsigned long long n) {
    unsigned long long result = 1;
    base = base % n;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % n;
        }
        exp = exp >> 1;
        base = (base * base) % n;
    }
    return result;
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

unsigned long long generatePrimeNumber() {
    unsigned long long n;
    int i, flag = 0;
    do {
        n = rand() % 10000 + 1000;
        if (n % 2 == 0) n++;

        for (i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) return n;

    } while (1);
}

int isPrimitive(unsigned long long a, unsigned long long n) {
    unsigned long long i, j, x, phi, primeFactors[100];
    int count = 0, primeFlag;

    phi = n - 1;

    for (i = 2; i <= phi; i++) {
        if (phi % i == 0) {
            primeFlag = 1;
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    primeFlag = 0;
                    break;
                }
            }
            if (primeFlag) {
                primeFactors[count++] = i;
            }
        }
    }

    for (i = 0; i < count; i++) {
        x = (phi / primeFactors[i]) + 1;
        if (power(a, x, n) == 1) {
            return 0;
        }
    }

    return 1;
}

int main() {

    unsigned long long p = generatePrimeNumber();
    unsigned long long q = generatePrimeNumber();

    unsigned long long n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);

    unsigned long long e;
    do {
        e = (rand() % (phi - 2)) + 2;
    } while (gcd(e, phi) != 1);

    unsigned long long d = 0;
    unsigned long long k = 1;

    while (1) {
        k += phi;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }

    // Verify
    unsigned long long message = 12345;
    unsigned long long encrypted = power(message, e, n);
    unsigned long long decrypted = power(encrypted, d, n);

    printf("Public Key: {%llu, %llu}\n", e, n);
    printf("Private Key: {%llu, %llu}\n", d, n);
    printf("Original Message: %llu\nEncrypted Message: %llu\nDecrypted Message: %llu\n", message, encrypted, decrypted);

    return 0;
}