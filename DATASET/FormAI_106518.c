//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * This is a cryptography implementation program that uses a unique combination of 
 * ASCII manipulation, random number generation, and conditional logic to obfuscate 
 * a message and encrypt it so that only the intended recipient can decode it.
 * The program takes a user input message, generates a key, and obfuscates the message
 * using the key. It then encrypts the message and key using a unique algorithm before
 * printing the encrypted results for the user to send. The recipient can then use this
 * program to decrypt the message and key, and use the key to decode the original message.
 */

// Function to generate a random number between 0 and max
int getRandomNumber(int max) {
    return rand() % max;
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time

    char message[100]; // User input message
    char key[100]; // Generated key for obfuscation
    char encrypted[200]; // Encrypted message and key
    char decrypted[100]; // Decrypted message

    // Prompt user to enter a message to encrypt
    printf("Enter message to encrypt (maximum 100 characters): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character from message

    // Generate key for obfuscation
    for (int i = 0; i < strlen(message); i++) {
        int num = (int)message[i]; // Convert character to ASCII number
        int random = getRandomNumber(10); // Generate random number between 0 and 9
        key[i] = num + random; // Add random number to ASCII number to obfuscate character
    }
    key[strlen(message)] = 0; // Add null terminator to key

    // Obfuscate message using key
    for (int i = 0; i < strlen(message); i++) {
        int num = (int)message[i]; // Convert character to ASCII number
        int keyNum = (int)key[i]; // Convert key character to ASCII number
        int obfuscatedNum = num + keyNum; // Add key number to ASCII number to obfuscate character
        char obfuscatedChar = (char)obfuscatedNum; // Convert obfuscated number back to character
        encrypted[i] = obfuscatedChar; // Add obfuscated character to encrypted message
    }
    encrypted[strlen(message)] = '|'; // Add separator between message and key
    strcat(encrypted, key); // Add key to encrypted message
    strcat(encrypted, "|"); // Add separator between key and encrypted message

    // Encrypt the encrypted message and key using a unique algorithm
    for (int i = 0; i < strlen(encrypted); i++) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            encrypted[i] += 10;
        } else if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            encrypted[i] += 5;
        } else if (encrypted[i] >= '0' && encrypted[i] <= '9') {
            encrypted[i] += 3;
        }
    }

    // Print the encrypted message and key for the user to send
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the encrypted message and key
    int separatorCount = 0; // Track number of separators encountered
    char keyCopy[100]; // Copy of key for decoding
    int keyIndex = 0; // Index to track position in keyCopy
    for (int i = 0; i < strlen(encrypted); i++) {
        if (encrypted[i] == '|') {
            separatorCount++;
            continue;
        }
        if (separatorCount == 0) { // Decode message
            int obfuscatedNum = (int)encrypted[i]; // Convert character to ASCII number
            int keyNum = (int)key[i]; // Convert corresponding key character to ASCII number
            int num = obfuscatedNum - keyNum; // Subtract key number from ASCII number to decode character
            char decodedChar = (char)num; // Convert decoded number back to character
            decrypted[i] = decodedChar; // Add decoded character to decrypted message
        } else if (separatorCount == 1) { // Copy key for decoding
            keyCopy[keyIndex] = encrypted[i];
            keyIndex++;
        }
    }
    decrypted[strlen(message)] = 0; // Add null terminator to decrypted message
    keyCopy[strlen(message)] = 0; // Add null terminator to key copy

    // Decrypt key using key copy
    char decodedKey[100]; // Decoded key for decoding message
    for (int i = 0; i < strlen(keyCopy); i++) {
        int num = (int)keyCopy[i]; // Convert character to ASCII number
        int random = getRandomNumber(10); // Generate random number between 0 and 9
        int decodedNum = num - random; // Subtract random number from ASCII number to decode character
        char decodedChar = (char)decodedNum; // Convert decoded number back to character
        decodedKey[i] = decodedChar; // Add decoded character to decoded key
    }
    decodedKey[strlen(message)] = 0; // Add null terminator to decoded key

    // Print the decrypted message and key
    printf("Decrypted message: %s\n", decrypted);
    printf("Decoded key: %s\n", decodedKey);

    return 0;
}