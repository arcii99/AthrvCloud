//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int millerRabinTest(ll d, ll n) {
    ll a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1) return TRUE;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return FALSE;
        if (x == n - 1) return TRUE;
    }
    return FALSE;
}

int isPrime(ll n, int k) {
    if (n == 2 || n == 3) return TRUE;
    if (n <= 1 || n % 2 == 0) return FALSE;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (int i = 0; i < k; ++i) {
        if (millerRabinTest(d, n) == FALSE) return FALSE;
    }
    return TRUE;
}

ll generatePrime(int numBits) {
    ll n = rand() % ((1 << numBits) - 1) + (1 << (numBits - 1));
    while (isPrime(n, 15) == FALSE) {
        n = rand() % ((1 << numBits) - 1) + (1 << (numBits - 1));
    }
    return n;
}

ll generatePublicKey(ll p, ll q) {
    ll n = p * q, e = 65537, phi = (p - 1) * (q - 1);
    while (gcd(e, phi) != 1) e = rand() % phi;
    return e;
}

ll generatePrivateKey(ll p, ll q, ll e) {
    ll n = p * q, phi = (p - 1) * (q - 1), d = 1;
    while ((d * e) % phi != 1) d++;
    return d;
}

int main() {
    srand(time(NULL));
    int numBits = 16;
    ll p = generatePrime(numBits), q = generatePrime(numBits), e = generatePublicKey(p, q), d = generatePrivateKey(p, q, e);
    printf("p = %lld\nq = %lld\ne = %lld\nd = %lld\n", p, q, e, d);
    return 0;
}