//FormAI DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void encrypt(char *cipher_text, int key)
{
    int len = strlen(cipher_text);
    for(int i=0;i<len;i++)
        cipher_text[i] += key;
}

void decrypt(char *cipher_text, int key)
{
    int len = strlen(cipher_text);
    for(int i=0;i<len;i++)
        cipher_text[i] -= key;
}

int main(){
    char cipher_text[MAX_SIZE];
    int key;

    printf("Enter text to encrypt: ");
    fgets(cipher_text, MAX_SIZE, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Original Text: %s\n", cipher_text);

    encrypt(cipher_text, key);
    printf("Encrypted Text: %s\n", cipher_text);

    decrypt(cipher_text, key);
    printf("Decrypted Text: %s\n", cipher_text);

    return 0;
}