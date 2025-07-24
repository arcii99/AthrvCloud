//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY "myEncryptionKey"

// Function to encrypt the input string
void encrypt(char *input, char *output)
{
    int i, len;
    char ch;
    len = strlen(input);
    for (i = 0; i < len; i++) 
    {
        ch = input[i] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
        sprintf(&output[i], "%02x", ch);
    }
}

// Function to decrypt the encrypted string
void decrypt(char *input, char *output)
{
    int i, len;
    char ch;
    len = strlen(input) / 2;
    for (i = 0; i < len; i++) 
    {
        sscanf(&input[i * 2], "%02x", &ch);
        ch = ch ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
        output[i] = ch;
    }
    output[i] = 0;
}

int main()
{
    char input[1024], output[2048], decrypted[1024];
    printf("Enter the input string to encrypt: ");
    scanf("%s", input);
    encrypt(input, output);
    printf("Encrypted string: %s\n", output);
    decrypt(output, decrypted);
    printf("Decrypted string: %s\n", decrypted);
    return 0;
}