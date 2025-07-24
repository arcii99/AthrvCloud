//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int p, q, n, phi, e, d, message, cipher, decrypted;

    // Step 1: Generate two random prime numbers, p and q
    do {
        p = rand() % 1000;
    } while (p < 2 || (p > 2 && p % 2 == 0));
    do {
        q = rand() % 1000;
    } while (q < 2 || (q > 2 && q % 2 == 0) || q == p);

    // Step 2: Calculate n = p * q
    n = p * q;

    // Step 3: Calculate phi(n) = (p - 1) * (q - 1)
    phi = (p - 1) * (q - 1);

    // Step 4: Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    do {
        e = rand() % phi;
    } while (e < 2 || gcd(e, phi) != 1);

    // Step 5: Calculate d such that e * d = 1 (mod phi(n))
    int k=1;
    while(1){
        k = k + phi;
        if(k%e==0){
            d = (k/e);
            break;
        }
    }

    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (n, d): (%d, %d)\n", n, d);

    // Step 6: Encryption
    printf("\nEncryption:\nEnter message (integer):");
    scanf("%d", &message);

    // Calculate c = m^e (mod n)
    cipher = (int)(pow(message, e)) % n;
    printf("Cipher text: %d\n", cipher);

    // Step 7: Decryption
    printf("\nDecryption:\nEnter cipher text (integer):");
    scanf("%d", &cipher);

    // Calculate m = c^d (mod n)
    decrypted = (int)(pow(cipher, d)) % n;
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}