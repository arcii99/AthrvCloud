//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ENCRYPTION_KEY 5
#define MAX_TEXT_LENGTH 1000

void encrypt(char *ciphertext, char *plaintext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 10 + 1; // create random number between 1 and 10
        char encrypted_char = (plaintext[i] + ENCRYPTION_KEY + random_number) % 256; // shift by encryption key and add random number, wrap around ASCII range
        snprintf(ciphertext + i*2, 3, "%02x", encrypted_char); // convert char to hexadecimal string and append to ciphertext
    }
}

void decrypt(char *plaintext, char *ciphertext) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i += 2) {
        int encrypted_char;
        sscanf(ciphertext + i, "%2x", &encrypted_char); // read next 2 hexadecimal characters from ciphertext as integer
        int decrypted_char = (encrypted_char - ENCRYPTION_KEY) % 256; // shift back by encryption key, unwrap around ASCII range
        plaintext[i/2] = (char) decrypted_char; // convert int to char and append to plaintext
    }
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    char plaintext[MAX_TEXT_LENGTH + 1];
    char ciphertext[MAX_TEXT_LENGTH*2 + 1];
    printf("Enter text to encrypt: ");
    fgets(plaintext, MAX_TEXT_LENGTH + 1, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove trailing newline from input
    printf("Plaintext: %s\n", plaintext);
    encrypt(ciphertext, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(plaintext, ciphertext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}