//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include<stdio.h>

int main()
{
    char data[100], key[100];
    int i, j;

    printf("Enter the message to encrypt: ");
    gets(data);

    printf("Enter key: ");
    gets(key);

    // Performing XOR operation
    for(i = 0, j = 0; data[i] != '\0'; ++i, ++j)
    {
        if(key[j] == '\0')
            j = 0;

        data[i] = data[i] ^ key[j];
    }

    printf("Encrypted message: %s", data);

    return 0;
}