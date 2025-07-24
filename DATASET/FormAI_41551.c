//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {
    char message[1000], key[100];
    int i, j, choice, length;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    length = strlen(message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    for(i=0; i<length; i++) {
        message[i] = message[i] + key[i % strlen(key)];
    }

    printf("Encrypted Message: %s\n", message);

    printf("Enter 1 to decrypt message or 2 to exit: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        for(i=0; i<length; i++) {
            message[i] = message[i] - key[i % strlen(key)];
        }
        printf("Decrypted Message: %s\n", message);
    }
    else {
        exit(0);
    }
}