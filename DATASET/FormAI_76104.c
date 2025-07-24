//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define ENCRYPTION_KEY 4

int main()
{
    char input[MAX_INPUT_SIZE];
    char encrypted[MAX_INPUT_SIZE];
    char decrypted[MAX_INPUT_SIZE];
    int i, length;
    
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    
    length = strlen(input);
    
    // Encrypt the input string
    for(i = 0; i < length; ++i)
    {
        encrypted[i] = input[i] + ENCRYPTION_KEY;
    }
    
    encrypted[i] = '\0';
    
    printf("\nEncrypted string: %s\n", encrypted);
    
    // Decrypt the encrypted string
    for(i = 0; i < length; ++i)
    {
        decrypted[i] = encrypted[i] - ENCRYPTION_KEY;
    }
    
    decrypted[i] = '\0';
    
    printf("\nDecrypted string: %s\n", decrypted);
    
    return 0;
}