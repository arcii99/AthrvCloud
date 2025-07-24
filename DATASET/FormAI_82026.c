//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Did someone say cryptography? Oh boy, this program is locked and loaded
// Let's get to cracking those codes, shall we?
// First, let's create a struct for our encryption key
typedef struct {
    int shift;
    char key[27];
} EncryptionKey;

// Now, let's create a function to generate a new encryption key
EncryptionKey generateEncryptionKey() {
    EncryptionKey key;
    key.shift = rand() % 26;
    for(int i = 0; i < 26; i++) {
        int idx = (i + key.shift) % 26;
        key.key[idx] = 'A' + i;
    }
    key.key[26] = '\0';
    return key;
}

// Time for some encryption magic!
void encrypt(char* message, EncryptionKey key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        char c = message[i];
        if(c >= 'A' && c <= 'Z') {
            int idx = c - 'A';
            message[i] = key.key[idx];
        }
    }
}

// And now, the moment of truth - our encryption program in action!
int main() {
    printf("Welcome to the Cryptography Program! Prepare to be amazed!\n");
    EncryptionKey key = generateEncryptionKey();
    printf("Your encryption key is: %s\n", key.key);
    
    char message[100];
    printf("Enter your message to encrypt: ");
    fgets(message, 100, stdin);
    
    encrypt(message, key);
    printf("Your encrypted message is: %s\n", message);
    
    return 0;
}

// Whew, that was fun! I hope you enjoyed encrypting and cracking codes with me!