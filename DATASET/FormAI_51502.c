//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char* message, int key) {
    int messageLen = strlen(message), i;
    for(i = 0; i < messageLen; ++i)
        message[i] += key;
}

void decrypt(char* message, int key) {
    int messageLen = strlen(message), i;
    for(i = 0; i < messageLen; ++i)
        message[i] -= key;
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message,100,stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}