//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
// A Visionary Implementation of Public-Key Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIME_LIMIT 1000

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int get_prime_number() {
    int prime;
    int prime_found = 0;
    while(!prime_found) {
        prime = rand() % PRIME_LIMIT + 2; // generate random number between 2 and PRIME_LIMIT
        if(is_prime(prime)) {
            prime_found = 1;
        }
    }
    return prime;
}

// Function to generate a public-private key pair
void generate_key_pair(int *public_key, int *private_key) {
    srand(time(NULL));
    int p = get_prime_number();
    int q = get_prime_number();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = get_prime_number();
    while(e < phi && (phi % e == 0)) {
        e = get_prime_number();
    }
    int d = 1;
    int k = 1;
    while(d != e) {
        d = (k * phi + 1) / e;
        k++;
    }
    *public_key = e;
    *private_key = d;
}

// Function to encrypt a message using public key
int encrypt_msg(int msg, int public_key, int n) {
    int cipher = 1;
    for(int i = 0; i < public_key; i++) {
        cipher = (cipher * msg) % n;
    }
    return cipher;
}

// Function to decrypt a message using private key
int decrypt_msg(int cipher, int private_key, int n) {
    int msg = 1;
    for(int i = 0; i < private_key; i++) {
        msg = (msg * cipher) % n;
    }
    return msg;
}

int main() {
    int public_key, private_key;
    generate_key_pair(&public_key, &private_key);
    
    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);
    
    int msg = 12345;
    int n = 1750;
    int cipher = encrypt_msg(msg, public_key, n);
    printf("Encrypted Message: %d\n", cipher);
    
    int decrypted_msg = decrypt_msg(cipher, private_key, n);
    printf("Decrypted Message: %d\n", decrypted_msg);
    
    return 0;
}