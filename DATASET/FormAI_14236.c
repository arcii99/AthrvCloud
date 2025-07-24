//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int num) {
    int i;
    if(num <= 1) return 0;
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return 0;
    }
    return 1;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int modPow(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int generatePrime(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    while(!isPrime(num)) {
        num = (rand() % (max - min + 1)) + min;
    }
    return num;
}

int generatePublicKey(int p, int q) {
    int n = p * q;
    int e = rand() % ((p - 1) * (q - 1) - 2) + 2;
    while(gcd(e, (p - 1) * (q - 1)) != 1) {
        e = rand() % ((p - 1) * (q - 1) - 2) + 2;
    }
    return e;
}

int generatePrivateKey(int p, int q, int e) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int i;
    for(i = 2; i < phi; i++) {
        if((e * i) % phi == 1) {
            return i;
        }
    }
}

int main() {
    srand(time(NULL));
    int p = generatePrime(1000, 2000);
    int q = generatePrime(2000, 3000);
    int n = p * q;
    int e = generatePublicKey(p, q);
    int d = generatePrivateKey(p, q, e);
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);
    int m = 12345;
    int encrypted = modPow(m, e, n);
    int decrypted = modPow(encrypted, d, n);
    printf("Message: %d\n", m);
    printf("Encrypted: %d\n", encrypted);
    printf("Decrypted: %d\n", decrypted);
    return 0;
}