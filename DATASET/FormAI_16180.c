//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the Greatest Common Divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int p, q, n, phi_n, e, d, message, ciphertext, decryptedtext;
    
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    
    // Find e where e and phi_n are coprime numbers
    do {
        printf("Enter a public key e such that 1 < e < %d and gcd(e, %d) = 1: ", phi_n, phi_n);
        scanf("%d", &e);
    } while (gcd(e, phi_n) != 1);
    
    // Find d where d satisfies the equation ed = 1 mod phi_n
    int k = 1;
    while (1) {
        if (((k * phi_n) + 1) % e == 0) {
            d = ((k * phi_n) + 1) / e;
            break;
        }
        k++;
    }
    
    // Encryption
    printf("\nEnter the message you want to encrypt (a positive integer): ");
    scanf("%d", &message);
    
    if (message < n) {
        ciphertext = (int) pow(message, e) % n;
        printf("The encrypted message is: %d\n", ciphertext);
    } else {
        printf("Message is too large to encrypt!\n");
        exit(EXIT_FAILURE);
    }
    
    // Decryption
    decryptedtext = (int) pow(ciphertext, d) % n;
    printf("The decrypted message is: %d\n", decryptedtext);
    
    return 0;
}