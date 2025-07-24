//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define key size for simplicity
#define KEY_SIZE 10

// Function to generate a random number within a given range
int random_number(int min_num, int max_num){
    return rand() % (max_num - min_num + 1) + min_num;
}

// Function to generate public and private keys
void generate_keys(int p, int q, int *public_key, int *private_key, int *n){
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    int e, d;
    do {
        e = random_number(2, phi-1);
    } while (gcd(e, phi) != 1);
    d = extended_euclidean_algorithm(e, phi);
    *public_key = e;
    *private_key = d;
}

// Function to encrypt a message using a public key
void encrypt(int *message, int message_length, int public_key, int n, int *encrypted_message){
    int i;
    for (i = 0; i < message_length; i++){
        encrypted_message[i] = power_modulo(message[i], public_key, n);
    }
}

// Function to decrypt an encrypted message using a private key
void decrypt(int *encrypted_message, int message_length, int private_key, int n, int *decrypted_message){
    int i;
    for (i = 0; i < message_length; i++){
        decrypted_message[i] = power_modulo(encrypted_message[i], private_key, n);
    }
}

// Function to calculate the greatest common divisor (gcd) of two numbers
int gcd(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the modular inverse of a number using the extended euclidean algorithm
int extended_euclidean_algorithm(int a, int b){
    int x = 0, y = 1, last_x = 1, last_y = 0, temp;
    while (b != 0){
        int q = a / b;
        int r = a % b;

        a = b;
        b = r;

        temp = x;
        x = last_x - q * x;
        last_x = temp;

        temp = y;
        y = last_y - q * y;
        last_y = temp;
    }
    return last_x;
}

// Function to calculate a number raised to a power modulo n (i.e. a^b mod n)
int power_modulo(int a, int b, int n){
    int result = 1;
    while (b > 0){
        if (b % 2 == 1){
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b = b / 2;
    }
    return result;
}

// Main function
int main(){
    // Seed the random number generator
    srand(time(NULL));

    // Generate two random prime numbers
    int p = 0, q = 0;
    while (!is_prime(p)){
        p = random_number(11, 29);
    }
    while (!is_prime(q) || p == q){
        q = random_number(11, 29);
    }

    // Generate public and private keys
    int public_key, private_key, n;
    generate_keys(p, q, &public_key, &private_key, &n);

    // Read in a message from the user
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Convert the message to an array of integers
    int message_length = strlen(message);
    int i;
    int message_array[message_length-1];
    for (i = 0; i < message_length-1; i++){
        message_array[i] = (int) message[i];
    }

    // Encrypt the message using the public key
    int encrypted_message[message_length-1];
    encrypt(message_array, message_length-1, public_key, n, encrypted_message);

    // Decrypt the encrypted message using the private key
    int decrypted_message[message_length-1];
    decrypt(encrypted_message, message_length-1, private_key, n, decrypted_message);

    // Convert the decrypted message back to a string and print it
    char decrypted_message_string[message_length];
    for (i = 0; i < message_length-1; i++){
        decrypted_message_string[i] = (char) decrypted_message[i];
    }
    decrypted_message_string[message_length-1] = '\0';
    printf("Original message: %s\n", message);
    printf("Decrypted message: %s\n", decrypted_message_string);

    return 0;
}

// Function to check if a number is prime
int is_prime(int n){
    if (n <= 1){
        return 0;
    }
    int i;
    for (i = 2; i <= n/2; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}