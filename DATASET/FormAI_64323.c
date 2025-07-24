//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char message[100], C[100], M[100];
    int i, j, k, n, p, q, e, d, phi;

    // Generate a random prime number p
    p = rand() % 26 + 1;
    printf("Generated prime number p: %d\n", p);

    // Generate another random prime number q
    q = rand() % 26 + 1;
    printf("Generated prime number q: %d\n", q);

    // Calculate the value of n
    n = p * q;
    printf("Calculated value of n: %d\n", n);

    // Calculate Euler's totient function of n
    phi = (p - 1) * (q - 1);
    printf("Euler's totient function of n: %d\n", phi);

    // Generate a random integer e coprime to phi
    for (i = 2; i < phi; i++) {
        if (phi % i != 0) {
            e = i;
            break;
        }
    }
    printf("Generated integer e: %d\n", e);

    // Calculate the value of d
    for (j = 1; j < phi; j++) {
        if ((e * j) % phi == 1) {
            d = j;
            break;
        }
    }
    printf("Calculated value of d: %d\n", d);

    // Ask the user to enter a message
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Encrypt the message using the public key (e, n)
    for (k = 0; message[k] != '\0'; k++) {
        for (i = 0; i < 62; i++) {
            if (message[k] == alpha[i]) {
                int temp = i;
                long int cipher = 1;
                for (j = 0; j < e; j++) {
                    cipher *= temp;
                    cipher %= n;
                }
                C[k] = cipher;
            }
        }
    }
    C[k] = '\0';
    printf("Encrypted message: %s\n", C);

    // Decrypt the message using the private key (d, n)
    for (k = 0; C[k] != '\0'; k++) {
        long int temp = C[k];
        long int plaintext = 1;
        for (j = 0; j < d; j++) {
            plaintext *= temp;
            plaintext %= n;
        }
        M[k] = alpha[plaintext];
    }
    M[k] = '\0';
    printf("Decrypted message: %s\n", M);

    return 0;
}