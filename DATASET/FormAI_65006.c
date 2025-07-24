//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PRIME_SIZE 8

// Function to check if a number is prime
int is_prime(int n) {
    if(n == 2 || n == 3)
        return 1;
    if(n % 2 == 0 || n % 3 == 0)
        return 0;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate a prime number
int generate_prime() {
    int num;
    do {
        num = rand() % (int)(pow(2, PRIME_SIZE) - 1) + (int)pow(2, PRIME_SIZE - 1);
    } while(!is_prime(num));
    return num;
}

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to calculate mod x power y
int mod_pow(int x, int y, int n) {
    int result = 1;
    while(y > 0) {
        if(y % 2 == 1) {
            result = (result * x) % n;
        }
        x = (x * x) % n;
        y = y / 2;
    }
    return result;
}

// Function to generate a public-private key pair
int* generate_key_pair() {
    static int key_pair[3];
    int p = generate_prime();
    int q = generate_prime();
    int n = p * q; // modulus
    int phi_n = (p - 1) * (q - 1); // totient of n
    int e; // public exponent
    do {
        e = rand() % (phi_n - 2) + 2; // e should be a number between [2, phi_n - 1] that is co-prime to phi_n
    } while(gcd(e, phi_n) != 1);
    key_pair[0] = e;
    int d; // private exponent
    int k = 1;
    while(1) {
        d = (1 + k * phi_n) / e;
        if((1 + k * phi_n) % e == 0) {
            break;
        }
        k++;
    }
    key_pair[1] = d;
    key_pair[2] = n;
    return key_pair;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate key pair
    int* key_pair = generate_key_pair();
    int e = key_pair[0];
    int d = key_pair[1];
    int n = key_pair[2];

    // Print key pair
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Encrypt a message
    char message[100];
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();
    int encrypted_message[100];
    for(int i = 0; message[i] != '\0'; i++) {
        encrypted_message[i] = mod_pow(message[i], e, n);
    }
    printf("Encrypted message: ");
    for(int i = 0; message[i] != '\0'; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    // Decrypt the message
    char decrypted_message[100];
    for(int i = 0; encrypted_message[i] > 0; i++) {
        decrypted_message[i] = mod_pow(encrypted_message[i], d, n);
    }
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}