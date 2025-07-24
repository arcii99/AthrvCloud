//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function to generate random prime number */
int generate_prime_number() {
    int num;
    int is_prime = 0;
    
    while (!is_prime) {
        num = rand() % 1000 + 1; // generate a random number between 1 and 1000
        is_prime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    return num;
}

/* function that returns the greatest common divisor */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

/* function to generate public and private keys */
void generate_keys(int *public_key, int *private_key) {
    int p = generate_prime_number();
    int q = generate_prime_number();
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 2;
    
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) {
            break;
        } else {
            e++;
        }
    }

    *public_key = e;
    
    int d = 1;
    while (((d * e) % phi_n) != 1) {
        d++;
    }

    *private_key = d;
    printf("Public key: %d\n", *public_key);
    printf("Private key: %d\n", *private_key);
}

/* function to encrypt a message using public key */
void encrypt_message(char *message, int public_key, int n) {
    int encrypted_message[strlen(message)];
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        int m = (int) message[i];
        int c = fmod(pow(m, public_key), n);
        encrypted_message[i] = c;
        printf("%d ", c);
    }
}

/* function to decrypt a message using private key */
void decrypt_message(int *encrypted_message, int length, int private_key, int n) {
    char decrypted_message[length];
    printf("\nDecrypted message: ");
    for (int i = 0; i < length; i++) {
        int c = encrypted_message[i];
        int m = fmod(pow(c, private_key), n);
        decrypted_message[i] = (char) m;
        printf("%c", decrypted_message[i]);
    }
    printf("\n");
}

/* main program */
int main() {
    int public_key, private_key;
    generate_keys(&public_key, &private_key);
    int n = generate_prime_number() * generate_prime_number(); // generate random n value
    char message[50];
    printf("Enter a message (max 50 characters): ");
    fgets(message, 50, stdin);
    int length = strlen(message) - 1; // exclude newline character from input
    int encrypted_message[length];
    encrypt_message(message, public_key, n);
    decrypt_message(encrypted_message, length, private_key, n);
    return 0;
}