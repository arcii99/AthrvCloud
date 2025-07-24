//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int i)
{
    if(str[i] == '\0')
        return;
    else
    {
        str[i] = str[i] + 3; // Adding a fixed value of 3 to each character in the string to encrypt it.
        encrypt(str,i+1); // Recursively calling the encrypt function to encrypt the next character in the string.
    }
}

void decrypt(char *str, int i)
{
    if(str[i] == '\0')
        return;
    else
    {
        str[i] = str[i] - 3; // Subtracting the fixed value of 3 from each character in the string to decrypt it.
        decrypt(str, i+1); // Recursively calling the decrypt function to decrypt the next character in the string.
    }
}

int main()
{
    char str[50];
    printf("Enter a string to encrypt: ");
    fgets(str,50,stdin);
    str[strcspn(str,"\n")] = '\0'; // Removing the newline character from the string.

    encrypt(str, 0); // Encrypting the string recursively.
    
    printf("Encrypted String: %s\n", str);
    
    decrypt(str, 0); // Decrypting the string recursively
    
    printf("Decrypted String: %s", str);
    
    return 0;
}