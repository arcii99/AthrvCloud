//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function to calculate modulus of two numbers
int calculateModulus(int a, int b) {
    int mod = a % b;
    return (mod < 0) ? mod + b : mod;
}

int main() {
    int p, q, n, phi, e, d, msg, encryptedMsg, decryptedMsg;

    printf("Enter two prime numbers: \n");
    scanf("%d%d", &p, &q);

    // calculate n
    n = p * q;

    // calculate phi(n)
    phi = (p - 1) * (q - 1);

    // choose a value for e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    for(int i = 2; i < phi; i++) {
        if(phi % i != 0) {
            e = i;
            break;
        }
    }

    // calculate d such that d * e is congruent to 1 modulo phi(n)
    for(int i = 1; i < phi; i++) {
        if(calculateModulus((e * i), phi) == 1) {
            d = i;
            break;
        }
    }

    printf("Public Key: (%d,%d)\n", e, n);
    printf("Private Key: (%d,%d)\n", d, n);

    printf("Enter a message to encrypt: ");
    scanf("%d", &msg);

    // encrypt the message
    int x = pow(msg, e);
    encryptedMsg = calculateModulus(x, n);

    printf("Encrypted Message: %d\n", encryptedMsg);

    // decrypt the message
    x = pow(encryptedMsg, d);
    decryptedMsg = calculateModulus(x, n);

    printf("Decrypted Message: %d\n", decryptedMsg);

    return 0;
}