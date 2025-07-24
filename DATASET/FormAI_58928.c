//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to encrypt a message using a simple Caesar Cipher */
void encrypt(char *message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        /* if the character is upper case */
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        /* if the character is lower case */
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter key: ");
    scanf("%d", &key);

    /* use the encrypt function to encrypt the message */
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);

    return 0;
}