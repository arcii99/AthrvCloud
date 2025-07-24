//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int key, option, i;
    char message[100], encryptedMsg[100], decryptedMsg[100];

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter a key value: ");
    scanf("%d", &key);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);

    if(option == 1) {
        for(i = 0; message[i] != '\0'; i++) {
            if(message[i] >= 'a' && message[i] <= 'z') {
                encryptedMsg[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
            else if(message[i] >= 'A' && message[i] <= 'Z') {
                encryptedMsg[i] = ((message[i] - 'A' + key) % 26) + 'A';
            }
            else {
                encryptedMsg[i] = message[i];
            }
        }
        printf("The encrypted message is: %s\n", encryptedMsg);
    }
    else if(option == 2) {
        for(i = 0; message[i] != '\0'; i++) {
            if(message[i] >= 'a' && message[i] <= 'z') {
                decryptedMsg[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
            else if(message[i] >= 'A' && message[i] <= 'Z') {
                decryptedMsg[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            }
            else {
                decryptedMsg[i] = message[i];
            }
        }
        printf("The decrypted message is: %s\n", decryptedMsg);
    }
    else {
        printf("Invalid option selected.\n");
    }

    return 0;
}