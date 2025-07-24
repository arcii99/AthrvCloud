//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This is a scalable implementation of the Caesar Cipher encryption algorithm
 * It takes in a message and a key and returns the encrypted message.
 */

typedef struct {
    int shift;  // determines how much to shift
} Key;

// This function takes in a message and a key and returns the encrypted message.
char* CaesarCipher(char* message, Key key) {
    int len = strlen(message);
    char *buffer = (char*)malloc(len + 1);
    
    for (int i = 0; i < len; ++i) {
        if (message[i] == ' ') { // ignore spaces
            buffer[i] = ' ';
        } else {
            buffer[i] = (message[i] + key.shift - 'a') % 26 + 'a';
        }
    }
    buffer[len] = '\0';
    return buffer;
}

int main() {
    char message[100];
    Key key;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strlen(message) - 1] = '\0';
  
    printf("Enter shift: ");
    scanf("%d", &key.shift);
  
    char* encryptedMessage = CaesarCipher(message, key);
  
    printf("Encrypted message: %s\n", encryptedMessage);
  
    free(encryptedMessage);
  
    return 0;
}