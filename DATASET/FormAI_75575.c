//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the given text
void encrypt(char *text, int shift)
{
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        i++;
    }
}

// Function to decrypt the given text
void decrypt(char *text, int shift)
{
    encrypt(text, 26 - shift);
}

int main()
{
    char text[100];
    int shift;

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    return 0;
}