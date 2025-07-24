//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vigenere_cipher(char *message, char *key)
{
    int i, j, k;
    char cipher[strlen(message)];

    for(i=0, j=0; i<strlen(message); i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            k = (key[j]-'a'+26)%26;
            cipher[i] = ((message[i]-'a'+k)%26) + 'a';
            j = (j+1)%strlen(key);
        }
        else if(message[i]>='A' && message[i]<='Z')
        {
            k = (key[j]-'A'+26)%26;
            cipher[i] = ((message[i]-'A'+k)%26) + 'A';
            j = (j+1)%strlen(key);
        }
        else
        {
            cipher[i] = message[i];
        }
    }

    printf("Cipher Text: %s", cipher);
}

int main()
{
    char message[50];
    char key[10];

    printf("Enter the message to be encrypted: ");
    fgets(message, 50, stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    vigenere_cipher(message, key);

    return 0;
}