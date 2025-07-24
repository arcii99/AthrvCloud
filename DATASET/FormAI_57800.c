//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    // Generate two random prime numbers
    int p = 61;
    int q = 53;

    // Calculate n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Generate a random number e such that 1 < e < phi and gcd(e, phi) = 1
    int e;
    srand(time(NULL));
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);

    // Calculate d using extended Euclidean algorithm
    int d = 0;
    int y = 0;
    int tmp_phi = phi;
    while (y != 1) {
        d++;
        y = (e * d) % tmp_phi;
    }

    // Encryption
    char message[1000] = "This is a message.";
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        int m = message[i] - 96; // Convert to integers (assuming lowercase letters only)
        int c = 1;
        int j;
        for (j = 0; j < e; j++) {
            c *= m;
            c %= n;
        }
        printf("%d ", c); // Print the encrypted message
    }
    printf("\n");

    // Decryption
    char decrypted[1000];
    int k = 0;
    for (i = 0; i < len; i += 2) {
        int c = 0;
        c += message[i] - 48;
        if (i + 1 < len) {
            c *= 10;
            c += message[i+1] - 48;
        }
        int m = 1;
        int j;
        for (j = 0; j < d; j++) {
            m *= c;
            m %= n;
        }
        decrypted[k++] = m + 96; // Convert back to characters
    }
    decrypted[k] = '\0';
    printf("%s\n", decrypted); // Print the decrypted message

    return 0;
}