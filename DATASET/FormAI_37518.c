//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
// Donald Knuth Style Implementation of a Public-Key Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIME_LIMIT 1000
#define MAX_NUMBER 100

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int generatePrime() {
    int primes[PRIME_LIMIT], count = 0;

    for (int i = 2; i < MAX_NUMBER; i++) {
        int flag = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            primes[count++] = i;
        }
    }

    int randomIndex = rand() % count;
    return primes[randomIndex];
}

int main() {
    srand(time(NULL));
    int p = generatePrime();
    int q = generatePrime();

    while (p == q) {
        q = generatePrime();
    }

    int n = p * q;
    int phiN = (p - 1) * (q - 1);
    int e = 2;

    // Finding e
    while (e < phiN) {
        if (gcd(e, phiN) == 1) {
            break;
        }
        e++;
    }

    int d = 0;

    // Finding d
    while (d <= 0) {
        int temp = d * e % phiN;
        if (temp == 1) {
            break;
        }
        d++;
    }

    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);
    return 0;
}