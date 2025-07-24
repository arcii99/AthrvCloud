//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num == 1 || num % 2 == 0) {
        return 0;
    }
    int i;
    for (i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int generate_prime() {
    int num = rand() % 10000 + 1000; // Generate a random number between 1000 and 10000
    while (!is_prime(num)) {
        num = rand() % 10000 + 1000;
    }
    return num;
}

// Function to calculate the greatest common denominator of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate the public and private keys
void generate_keys(int *public_key, int *private_key) {
    // Generate two prime numbers
    int p = generate_prime();
    int q = generate_prime();

    // Calculate n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a random number e such that 1 < e < phi and gcd(e,phi) = 1
    int e = rand() % (phi - 2) + 2;
    while (gcd(e, phi) != 1) {
        e = rand() % (phi - 2) + 2;
    }

    // Calculate d such that d*e = 1 mod phi
    int d = 0;
    int k = 1;
    while (1) {
        d = (1 + k * phi) / e;
        if ((d * e) % phi == 1) {
            break;
        }
        k++;
    }

    // Set public and private keys
    public_key[0] = n;
    public_key[1] = e;
    private_key[0] = n;
    private_key[1] = d;
}

// Function to encrypt a message
void encrypt(int *public_key, char *message, int *encrypted_message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        encrypted_message[i] = (int) pow((double) message[i], (double) public_key[1]) % public_key[0];
    }
}

// Function to decrypt a message
void decrypt(int *private_key, int *encrypted_message, char *decrypted_message) {
    int i;
    for (i = 0; encrypted_message[i] > 0; i++) {
        decrypted_message[i] = (char) pow((double) encrypted_message[i], (double) private_key[1]) % private_key[0];
    }
    decrypted_message[i] = '\0';
}

int main() {
    // Seed the random number generator
    srand((unsigned int) time(NULL));

    // Generate public and private keys
    int public_key[2];
    int private_key[2];
    generate_keys(public_key, private_key);

    // Get message from user
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    // Encrypt the message
    int encrypted_message[1000];
    encrypt(public_key, message, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: ");
    int i;
    for (i = 0; encrypted_message[i] > 0; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    // Decrypt the message
    char decrypted_message[1000];
    decrypt(private_key, encrypted_message, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}