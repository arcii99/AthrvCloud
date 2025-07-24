//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b) { // function to find gcd
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int is_prime(long n) { // function to check for prime
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int main() {
    srand(time(NULL)); // generate random seed
    long p, q, n, phi, e, d, message, c, decrypted;
    while (1) { // loop to ensure p and q are primes
        p = rand() % 100 + 1;
        q = rand() % 100 + 1;
        if (is_prime(p) && is_prime(q))
            break;
    }
    n = p * q; // calculate n
    phi = (p - 1) * (q - 1); // calculate phi
    while (1) { // loop to find e
        e = rand() % phi + 1;
        if (gcd(e, phi) == 1)
            break;
    }
    d = 0;
    while (1) { // loop to find d
        if ((d * e) % phi == 1)
            break;
        d++;
    }
    printf("Public Key: (%ld, %ld)\nPrivate Key: (%ld, %ld)\n", e, n, d, n); // print keys
    printf("Enter the message to be encrypted: ");
    scanf("%ld", &message);
    c = ((long)pow(message, e)) % n; // calculate ciphertext
    printf("Encrypted Message: %ld\n", c);
    decrypted = ((long)pow(c, d)) % n; // calculate decrypted message
    printf("Decrypted Message: %ld\n", decrypted);
    return 0;
}