//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Cryptography Implementation

#include <stdio.h>
#include <string.h>

// Cipher function
char* cipher(char* message, int key) {
    int i;
    char* output = malloc(strlen(message));
    
    for(i = 0; i < strlen(message); i++) {
        output[i] = ((message[i] - 'a' + key) % 26) + 'a';
    }
    
    return output;
}

// Decipher function
char* decipher(char* message, int key) {
    int i;
    char* output = malloc(strlen(message));
    
    for(i = 0; i < strlen(message); i++) {
        output[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
    }
    
    return output;
}

int main() {
    char* message = "parting is such sweet sorrow";
    int key = 4;
    
    // Romeo encrypts the message for Juliet
    char* encrypted_message = cipher(message, key);
    printf("Romeo: My dearest Juliet, this is the message I have for you: %s\n", encrypted_message);
    
    // Juliet receives the message and decrypts it
    char* decrypted_message = decipher(encrypted_message, key);
    printf("Juliet: Oh, Romeo, I have deciphered your message: %s\n", decrypted_message);
    
    return 0;
}