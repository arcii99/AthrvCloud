//FormAI DATASET v1.0 Category: Bitwise operations ; Style: immersive
#include <stdio.h>

int main() {
    char message[] = "Welcome to the Bitwise World!!";
    int length = sizeof(message) / sizeof(char) - 1; // minus 1 to exclude null terminator
    printf("Original message: %s\n", message);
    printf("Message length: %d\n\n", length);

    // Using bitwise OR to scramble the message
    for(int i = 0; i < length; i++) {
        message[i] = message[i] | 0xB7; // XOR with 10110111
    }
    printf("Scrambled message: %s\n\n", message);

    // Using bitwise AND to unscramble the message
    for(int i = 0; i < length; i++) {
        message[i] = message[i] & 0xB7; // XOR with 10110111
    }
    printf("Unscrambled message: %s\n\n", message);

    // Using bitwise shift to encode a secret message
    char secretMessage[] = "secret message";
    int sLength = sizeof(secretMessage) / sizeof(char) - 1; // minus 1 to exclude null terminator
    for(int i = 0; i < sLength; i++) {
        secretMessage[i] = secretMessage[i] << 3; // shift left by 3 bits
    }
    printf("Secret message: %s\n\n", secretMessage);

    // Using bitwise shift to decode the secret message
    for(int i = 0; i < sLength; i++) {
        secretMessage[i] = secretMessage[i] >> 3; // shift right by 3 bits
    }
    printf("Decoded secret message: %s\n\n", secretMessage);

    return 0;
}