//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
// Romeo and Juliet's Cryptography Implementation

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char plaintext[MAX_LEN], ciphertext[MAX_LEN];
    int shift, i;

    printf("My fair Juliet, please enter your message to encrypt (max %d characters):\n", MAX_LEN-1);
    fgets(plaintext, MAX_LEN, stdin);

    printf("Sweet Romeo, please enter the shift value (1-25):\n");
    scanf("%d", &shift);

    // Encryption
    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
            ciphertext[i] = ((plaintext[i] - 'A') + shift) % 26 + 'A';
        else if (islower(plaintext[i]))
            ciphertext[i] = ((plaintext[i] - 'a') + shift) % 26 + 'a';
        else
            ciphertext[i] = plaintext[i];
    }
    ciphertext[i] = '\0';
    
    printf("Juliet's encrypted message:\n%s\n", ciphertext);

    // Decryption
    for (i = 0; i < strlen(ciphertext); i++)
    {
        if (isupper(ciphertext[i]))
            plaintext[i] = ((ciphertext[i] - 'A') - shift + 26) % 26 + 'A';
        else if (islower(ciphertext[i]))
            plaintext[i] = ((ciphertext[i] - 'a') - shift + 26) % 26 + 'a';
        else
            plaintext[i] = ciphertext[i];
    }
    plaintext[i] = '\0';

    printf("Romeo's decrypted message:\n%s\n", plaintext);

    return 0;
}