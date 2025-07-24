//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int modInverse(int a, int m) {
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

int generateKeys(int *pub_key, int *prv_key) {
    int p, q, n, phiN, e, d, max, i, j, flag;
    int primes[10000];

    srand(time(0));

    printf("Generating prime numbers...\n");

    primes[0] = 2;
    primes[1] = 3;
    max = 2;

    for (i = 5; max < 10000; i += 2) {
        flag = 0;
        for (j = 1; primes[j] * primes[j] <= i; j++) {
            if (i % primes[j] == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            primes[max++] = i;
        }
    }

    p = primes[rand() % 10000];
    q = primes[rand() % 10000];

    while (p == q) {
        q = primes[rand() % 10000];
    }

    n = p * q;
    phiN = (p - 1) * (q - 1);

    e = 10001;

    while (gcd(e, phiN) != 1) {
        e = primes[rand() % 10000];
    }

    d = modInverse(e, phiN);

    *pub_key = e;
    *prv_key = d;

    return n;
}

int main() {
    int pub_key, prv_key, n;
    int input, encrypted, decrypted;

    n = generateKeys(&pub_key, &prv_key);

    printf("Public Key: %d\nPrivate Key: %d\nN: %d\n", pub_key, prv_key, n);

    printf("Enter a number to encrypt: ");
    scanf("%d", &input);

    encrypted = (int)(pow(input, pub_key)) % n;
    decrypted = (int)(pow(encrypted, prv_key)) % n;

    printf("Encrypted: %d\n", encrypted);
    printf("Decrypted: %d\n", decrypted);

    return 0;
}