//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char *message, int key) {
    int len = strlen(message);
    char *encrypted_message = (char*) malloc((len+1) * sizeof(char));
    for (int i=0; i<len; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            encrypted_message[i] = ((ch - 'a' + key) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            encrypted_message[i] = ((ch - 'A' + key) % 26) + 'A';
        } else {
            encrypted_message[i] = ch;
        }
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

int main() {
    printf("Welcome to the unique C Encryption program!\n");
    printf("Enter the message to encrypt: ");
    char *message = (char*) malloc((1000) * sizeof(char));
    fgets(message, 1000, stdin);
    printf("Enter the key (an integer between 1 and 25): ");
    int key;
    scanf("%d", &key);
    getchar();
    if (key < 1 || key > 25) {
        printf("Invalid key! Key should be an integer between 1 and 25.\n");
        exit(0);
    }
    char *encrypted_message = encrypt(message, key);
    printf("\n------------------------------------\n");
    printf("Original message: %s", message);
    printf("Encrypted message: %s", encrypted_message);
    printf("------------------------------------\n");
    free(message);
    free(encrypted_message);
    return 0;
}