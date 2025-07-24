//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "1234" // secret key for encryption and decryption

void encrypt(char *str)
{
    int keyLength = strlen(KEY);
    int strLength = strlen(str);
    for (int i = 0; i < strLength; i++) {
        str[i] = str[i] ^ KEY[i % keyLength];
    }
}

void decrypt(char *str)
{
    encrypt(str); // decryption is same as encryption in XOR cipher
}

int main()
{
    char message[1024];
    printf("Enter a message: ");
    fgets(message, 1024, stdin);
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}