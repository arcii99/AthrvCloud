//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function takes in a string and a key to encrypt the string */
void encrypt(char *str, int key)
{
    int len = strlen(str);
    
    // Iterate through each character in the string
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        
        // If the character is a lowercase letter
        if (c >= 'a' && c <= 'z')
        {
            // Shift the character by the key
            c = ((c - 'a') + key) % 26 + 'a';
            str[i] = c;
        }
        // If the character is an uppercase letter
        else if (c >= 'A' && c <= 'Z')
        {
            // Shift the character by the key
            c = ((c - 'A') + key) % 26 + 'A';
            str[i] = c;
        }
    }
}

int main()
{
    char str[100];
    int key;
    
    printf("Welcome to the C Encryption program!\n");
    printf("Please enter a string to encrypt: ");
    scanf("%s", str);
    
    printf("Please enter a key to use for encryption: ");
    scanf("%d", &key);
    
    encrypt(str, key);
    
    printf("The encrypted string is: %s\n", str);
    
    return 0;
}