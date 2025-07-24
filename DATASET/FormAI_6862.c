//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Euclid's extended algorithm for finding the multiplicative inverse of a number
int EuclidExtended(int a, int b, int* x, int* y){
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = EuclidExtended(b % a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Function to calculate modulus for large numbers
int Modulus(int x, int y, int p){
    int res = 1;
    x %= p;

    while (y){
        if (y & 1){
            res = (res * x) % p;
        }

        y >>= 1;
        x = (x * x) % p;
    }

    return res;
}

// Function to generate public and private keys
void GenerateKeys(int prime1, int prime2, int* public_key, int* private_key){
    int n = prime1 * prime2;
    int phi = (prime1 - 1) * (prime2 - 1);

    // Finding a number e which is relatively prime to phi
    int e = 2;
    while (e < phi){
        if (EuclidExtended(e, phi, public_key, private_key) == 1){
            break;
        } else {
            e++;
        }
    }

    // Finding the private key
    *private_key = (*private_key % phi + phi) % phi;
}

// Main function
int main(){
    int prime1 = 17, prime2 = 11;
    int public_key, private_key;

    GenerateKeys(prime1, prime2, &public_key, &private_key);

    printf("Public key: (%d, %d)\n", public_key, prime1 * prime2);
    printf("Private key: (%d, %d)\n", private_key, prime1 * prime2);

    int message = 88;
    int encrypted_message = Modulus(message, public_key, prime1 * prime2);
    int decrypted_message = Modulus(encrypted_message, private_key, prime1 * prime2);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}