//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift);

int main()
{
    char text[100];
    int shift;
    printf("Enter text to encrypt: ");
    fgets(text, 100, stdin);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    encrypt(text, shift);
    printf("Encrypted text: %s", text);
    return 0;
}

void encrypt(char *text, int shift)
{
    int i, letter;
    for(i = 0; i < strlen(text); i++)
    {
        letter = text[i];
        if(letter >= 'a' && letter <= 'z')
        {
            letter = letter + shift;
            if(letter > 'z')
            {
                letter = letter - 'z' + 'a' - 1;
            }
            text[i] = letter;
        }
        else if(letter >= 'A' && letter <= 'Z')
        {
            letter = letter + shift;
            if(letter > 'Z')
            {
                letter = letter - 'Z' + 'A' - 1;
            }
            text[i] = letter;
        }
    }
}