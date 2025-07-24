//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string
void encrypt(char *str)
{
    int i, len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if(i%2 == 0) // If index is even
            str[i] += 3;
        else // If index is odd
            str[i] -= 5;
    }
}

// Function to decrypt a string
void decrypt(char *str)
{
    int i, len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if(i%2 == 0) // If index is even
            str[i] -= 3;
        else // If index is odd
            str[i] += 5;
    }
}

int main()
{
    char str[50];
    printf("Enter a string to encrypt: ");
    fgets(str, 50, stdin);
    printf("\nOriginal string: %s", str);
    encrypt(str);
    printf("\nEncrypted string: %s", str);
    decrypt(str);
    printf("\nDecrypted string: %s", str);
    return 0;
}