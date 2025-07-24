//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;
    char text[50];

    printf("Enter a text string: ");
    fgets(text, 50, stdin);

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <='z')
        {
            text[i] = (text[i] - 'a' + n) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + n) % 26 + 'A';
        }
    }

    printf("Original text: %s\n", text);

    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - n + 26) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' - n + 26) % 26 + 'A';
        }
    }

    printf("Decrypted text: %s\n", text);

    return 0;
}