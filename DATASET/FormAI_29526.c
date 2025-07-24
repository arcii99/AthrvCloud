//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *plaintext, char *key);

int main()
{
    char plaintext[1000];
    char key[100];
    char *ciphertext;
    
    printf("Enter the plaintext:");
    fgets(plaintext, 1000, stdin);
    printf("Enter the key:");
    fgets(key, 100, stdin);
    
    ciphertext = encrypt(plaintext, key);
    
    printf("\nCiphertext: %s\n", ciphertext);
    
    free(ciphertext);
    return 0;
}

char* encrypt(char *plaintext, char *key)
{
    int p_len = strlen(plaintext) - 1;
    int k_len = strlen(key) - 1;
    int i, j;
    char *ciphertext = (char*)malloc(sizeof(char) * (p_len + 1));
    
    for(i = 0, j = 0; i < p_len; i++, j++)
    {
        if(j == k_len)
            j = 0;
            
        ciphertext[i] = ((plaintext[i] + key[j]) % 26) + 'A';
    }
    
    ciphertext[i] = '\0';
    
    return ciphertext;
}