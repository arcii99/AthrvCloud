//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
// Romeo and Juliet's Public-Key Algorithm Implementation

#include <stdio.h>

int main() {

    // Declarations
    int p, q, n, phi, e, d, m, c, decrypted_m;
    int prime_check1, prime_check2;

    // Initializations
    p = 7;
    q = 11;
    n = p * q;
    phi = (p-1)*(q-1);

    // Search for suitable e and d values
    for(e = 2; e < phi; e++) {

        prime_check1 = 1;
        prime_check2 = 1;

        // Check if e is prime
        for(int i = 2; i < e; i++) {

            if(e % i == 0) {
                prime_check1 = 0;
                break;
            }
        }

        // Check if (e * d) % phi = 1
        if(prime_check1 == 1) {
            for(d = 2; d < phi; d++) {
                if((e * d) % phi == 1) {
                    prime_check2 = 1;
                    break;
                }
            }
        }

        // If e and d values are suitable, break from loop
        if(prime_check1 == 1 && prime_check2 == 1) {
            break;
        }
    }

    // Display e and d values
    printf("Public Key (e,n): (%d,%d)\n", e, n);
    printf("Private Key (d,n): (%d,%d)\n\n", d, n);

    // Encryption Process
    printf("Enter Message (M) to be Encrypted: ");
    scanf("%d", &m);

    c = 1;
    for(int i = 0; i < e; i++) {
        c *= m;
        c %= n;
    }
    printf("\nEncrypted Message (C): %d\n\n", c);

    // Decryption Process
    decrypted_m = 1;
    for(int i = 0; i < d; i++) {
        decrypted_m *= c;
        decrypted_m %= n;
    }
    printf("Decrypted Message (M): %d\n", decrypted_m);

    return 0;
}