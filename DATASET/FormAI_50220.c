//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
// Header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Euclidean Algorithm
int euclids_algorithm(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return euclids_algorithm(b, a % b);
  }
}

// Multiplicative Inverse
int multiplicative_inverse(int phi, int e) {
    int i, inverse;
    for (i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            inverse = i;
            break;
        }
    }
    return inverse;
}

int main() {
    // User Inputs
    int p, q, n, phi, e, d, plaintext, ciphertext, decrypted_text;
    printf("Enter value of p: ");
    scanf("%d", &p);
    printf("Enter value of q: ");
    scanf("%d", &q);

    // Calculations
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (e = 2; e < phi; e++) {
        if (euclids_algorithm(e, phi) == 1) {
            break;
        }
    }
    d = multiplicative_inverse(phi, e);

    // Encryption
    printf("Enter plaintext: ");
    scanf("%d", &plaintext);
    ciphertext = pow(plaintext, e);
    ciphertext = fmod(ciphertext, n);
    printf("Ciphertext: %d\n", ciphertext);

    // Decryption
    decrypted_text = pow(ciphertext, d);
    decrypted_text = fmod(decrypted_text, n);
    printf("Decrypted Text: %d\n", decrypted_text);

    return 0;
}