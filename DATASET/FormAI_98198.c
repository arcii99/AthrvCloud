//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given string
void encrypt(char *str, int key)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++) 
    {
        // For uppercase characters
        if (str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = ((str[i] - 'A') + key) % 26 + 'A';
 
        // For lowercase characters
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = ((str[i] - 'a') + key) % 26 + 'a';
        
        // For non-alphabetic characters
        else
            str[i] = str[i];
    }
    printf("\nEncrypted string is: %s\n", str);
}
 
int main(void)
{
    char str[100];
    int key;
    
    // Taking input from user
    printf("Enter the string to be encrypted: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter the key (between 1 to 25): ");
    scanf("%d", &key);
    
    // Checking for valid key range
    if (key>25 || key<1)
    {
        printf("\nInvalid key!\n");
        exit(0);
    }

    // Calling encryption function
    encrypt(str, key);

    return 0;
}