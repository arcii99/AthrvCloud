//FormAI DATASET v1.0 Category: Encryption ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char* encrypt(char *plaintext, int key);

int main()
{
    char plaintext[1000];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(plaintext, 1000, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    char *ciphertext = encrypt(plaintext, key);
    printf("Encrypted message: %s\n", ciphertext);

    free(ciphertext);
    return 0;
}

char* encrypt(char *plaintext, int key)
{
    char *ciphertext = (char*) malloc(strlen(plaintext) * sizeof(char));
    int i;

    for(i = 0; i < strlen(plaintext); i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
                ciphertext[i] = ((plaintext[i] - 'a') + key) % 26 + 'a';
            else
                ciphertext[i] = ((plaintext[i] - 'A') + key) % 26 + 'A';
        }
        else
            ciphertext[i] = plaintext[i];
    }

    ciphertext[i] = '\0';
    return ciphertext;
}