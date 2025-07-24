//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TEXT_LENGTH 100
#define MAX_KEY_LENGTH 100

char* encrypt(char text[], char key[]);
char* decrypt(char cipher[], char key[]);

int main(void)
{
    char plain_text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char* cipher_text;
    char* decipher_text;

    printf("Enter the plain text: ");
    fgets(plain_text, MAX_TEXT_LENGTH, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    cipher_text = encrypt(plain_text, key);
    printf("Encrypted Text: %s", cipher_text);

    decipher_text = decrypt(cipher_text, key);
    printf("Decrypted Text: %s", decipher_text);

    free(cipher_text);
    free(decipher_text);

    return 0;
}

char* encrypt(char text[], char key[])
{
    int text_length = strlen(text)-1;
    int key_length = strlen(key)-1;
    char* cipher_text = (char*)malloc(sizeof(char)*text_length);
    for(int i=0; i<text_length; i++)
    {
        cipher_text[i] = (text[i] + key[i%key_length])%256;
    }
    return cipher_text;
}

char* decrypt(char cipher[], char key[])
{
    int cipher_length = strlen(cipher);
    int key_length = strlen(key)-1;
    char* decipher_text = (char*)malloc(sizeof(char)*cipher_length);
    for(int i=0; i<cipher_length; i++)
    {
        decipher_text[i] = (cipher[i] - key[i%key_length] + 256)%256;
    }
    return decipher_text;
}