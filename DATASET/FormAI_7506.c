//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN_VAL 1000
#define MAX_VAL 9999

int gcd(int a, int b) {
    if (a == 0) {
        return b;
   }

    return gcd(b % a, a);
}

int generatePrime() {
    int prime = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
    int i;

    for (i = 2; i <= sqrt(prime); i++) {
        if (prime % i == 0) {
            break;
       }
   }

    if (i > sqrt(prime)) {
        return prime;
   } else {
        return generatePrime();
   }
}

int main() {
    srand(time(0));

    int p, q, n, e, d;
    p = generatePrime();
    q = generatePrime();

    n = p * q;

    int phi_n = (p - 1) * (q - 1);

    do {
        e = rand() % phi_n;
    } while (e < 2 || gcd(e, phi_n) != 1);

    int k = 2;
    d = (1 + (k * phi_n)) / e;

    printf("Public Key: (%d, %d)\n", n, e);
    printf("Private Key: (%d, %d)\n", n, d);

    return 0;
}