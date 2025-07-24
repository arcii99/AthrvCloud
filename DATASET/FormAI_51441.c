//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Encryption function
void encrypt(char text[], char key[], char encrypted_text[])
{
    int len = strlen(text);
    int klen = strlen(key);
    int i = 0, j = 0, k = 0;

    for (i = 0; i < len; ++i)
    {
        if (text[i] == ' ')
        {
            encrypted_text[i] = ' ';
            continue;
        }

        // Apply encryption algorithm
        int x = text[i] - 'a';
        int y = key[j] - 'a';
        int z = (x + y) % 26;
        encrypted_text[i] = z + 'a';

        // Update key index
        j++;
        if (j >= klen)
            j = 0;
    }
    encrypted_text[i] = '\0';
}

int main()
{
    char text[100], key[100], encrypted_text[100];

    printf("Enter the plain text : ");
    scanf("%[^\n]%*c", text);

    printf("Enter the key : ");
    scanf("%[^\n]%*c", key);

    encrypt(text, key, encrypted_text);

    printf("Encrypted Text : %s\n", encrypted_text);

    return 0;
}