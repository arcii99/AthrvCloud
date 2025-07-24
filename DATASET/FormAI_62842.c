//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute GCD of x and y
int gcd(int x, int y) {
    if (y == 0) 
        return x;
    return gcd(y, x % y);
}

// Function to generate a random prime number between min and max
int gen_prime(int min, int max) {
    int num, i, j;
    for (i = min; i <= max; i++) {
        num = i;
        for (j = 2; j <= sqrt(num); j++) {
            if (num % j == 0) {
                break;
            }
        }
        if (j > sqrt(num)) {
            return num;
        }
    }
    return 0;
}

// Function to compute modular exponentiation
int modular_pow(int base, int exponent, int modulus) {
    if (modulus == 1)
        return 0;

    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    int p, q, n, phi_n, e, d, message, encrypted_msg, decrypted_msg;
    
    // Step 1: Generate two random prime numbers p and q
    p = gen_prime(100, 200);
    q = gen_prime(200, 300);
    printf("Generated prime numbers: p=%d, q=%d\n", p, q);

    // Step 2: Compute n = p*q
    n = p * q;
    printf("n=%d\n", n);

    // Step 3: Compute phi(n) = (p-1)*(q-1)
    phi_n = (p - 1) * (q - 1);
    printf("phi_n=%d\n", phi_n);

    // Step 4: Choose a public exponent e such that 1 < e < phi_n and gcd(e, phi_n) = 1
    e = 3;
    while (gcd(e, phi_n) > 1) {
        e = e + 2;
    }
    printf("e=%d\n", e);

    // Step 5: Compute the private exponent d such that d ≡ (1 mod phi(n))/(e mod phi(n))
    int k = 1;
    while ((k * phi_n + 1) % e != 0) {
        k++;
    }
    d = (k * phi_n + 1) / e;
    printf("d=%d\n", d);

    // Step 6: Encryption
    printf("Enter the message to encrypt: ");
    scanf("%d", &message);
    encrypted_msg = modular_pow(message, e, n);
    printf("Encrypted message: %d\n", encrypted_msg);

    // Step 7: Decryption
    decrypted_msg = modular_pow(encrypted_msg, d, n);
    printf("Decrypted message: %d\n", decrypted_msg);

    return 0;
}