//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
/* 
This program implements the Claude Shannon's One-Time Pad encryption algorithm.
It takes a message to be encrypted as input and generates a random key of the same size as the message.
It then encrypts the message using the key and outputs the encrypted message along with the key used for encryption.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_key(char *key, int size) {
    // Generates a random key of the given size
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256; // Generate a random byte
    }
}

void encrypt(char *message, int size, char *key) {
    // Encrypts the message using the given key
    for (int i = 0; i < size; i++) {
        message[i] = message[i] ^ key[i]; // XOR operation to encrypt the byte
    }
}

void print_hex(char *data, int size) {
    // Prints the given data in hexadecimal format
    for (int i = 0; i < size; i++) {
        printf("%02x ", (unsigned char)data[i]); // Print the byte in hexadecimal format
        if ((i + 1) % 16 == 0) {
            printf("\n"); // Print a new line after every 16 bytes
        }
    }
}

int main() {
    char message[256];
    char key[256];
    int size;

    printf("Enter the message to be encrypted (up to 256 bytes):\n");
    fgets(message, sizeof(message), stdin); // Read the input message from the user
    
    // Remove the newline character from the input
    size = strlen(message);
    if (size > 0 && message[size-1] == '\n') {
        message[size-1] = '\0';
        size = size - 1;
    }
    
    printf("Message to be encrypted:\n");
    print_hex(message, size); // Print the message in hexadecimal format
    
    generate_key(key, size); // Generate a random key of the same size as the message
    
    printf("Generated key:\n");
    print_hex(key, size); // Print the key in hexadecimal format
    
    encrypt(message, size, key); // Encrypt the message using the key
    
    printf("Encrypted message:\n");
    print_hex(message, size); // Print the encrypted message in hexadecimal format
    
    return 0;
}