//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const long long p = 31;
const long long q = 29;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;

    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    } 
    return res;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    long long n = p * q;
    long long e = 2;
    long long phi = (p-1) * (q-1);

    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        } else {
            e++;
        }
    }

    long long d = 2;
    long long k = (d * e - 1) / phi;

    while (d < phi) {
        if ((k * phi + 1) % d == 0) {
            break;
        } else {
            d++;
        }
    }

    long long pu[] = {e, n};
    long long pr[] = {d, n};

    char plaintext[100];
    printf("Enter plaintext: ");
    scanf("%[^\n]s", plaintext);

    int len = strlen(plaintext);

    long long ct[len];
    long long pt[len];

    for (int i = 0; i < len; i++) {
        pt[i] = plaintext[i];
        ct[i] = power(pt[i], pu[0], pu[1]);
    }

    printf("\nEncrypted ciphertext:");
    for (int i = 0; i < len; i++) {
        printf("%lld ", ct[i]);
    }

    printf("\nDecrypted plaintext: ");
    for (int i = 0; i < len; i++) {
        pt[i] = power(ct[i], pr[0], pr[1]);
        printf("%c", pt[i]);
    }

    return 0;
}