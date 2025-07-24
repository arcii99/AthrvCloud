//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char *message, char *key)
{
    int i, j = 0;
    int m_len = strlen(message);
    int k_len = strlen(key);
    char encrypted[MAX_LENGTH];
    
    for(i = 0; i < m_len; i++)
    {
        encrypted[i] = message[i] ^ key[j];
        j++;
        
        if(j == k_len)
        {
            j = 0;
        }
    }
    
    printf("Encrypted Message: %s\n", encrypted);
}

void decrypt(char *encrypted, char *key)
{
    int i, j = 0;
    int e_len = strlen(encrypted);
    int k_len = strlen(key);
    char decrypted[MAX_LENGTH];
    
    for(i = 0; i < e_len; i++)
    {
        decrypted[i] = encrypted[i] ^ key[j];
        j++;
        
        if(j == k_len)
        {
            j = 0;
        }
    }
    
    printf("Decrypted Message: %s\n", decrypted);
}

int main()
{
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];
    
    printf("Enter Message to Encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    
    printf("Enter Encryption Key: ");
    fgets(key, MAX_LENGTH, stdin);
    
    /* Remove newline character from input */
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    encrypt(message, key);
    decrypt("9\x0a9\x0bE\x1C\x13Q\x1A\x13M\r", key);
    
    return 0;
}