//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *text);
void toLower(char *text);
void replaceVowels(char *text);

int main()
{
    char text[500];

    printf("Enter some text: ");
    fgets(text, 500, stdin);

    printf("\nYou entered: %s", text);

    printf("\nThere are %d words in the text.\n", countWords(text));

    toLower(text);
    printf("\nText in lowercase: %s", text);

    replaceVowels(text);
    printf("\nText with vowels replaced: %s", text);

    return 0;
}

int countWords(char *text)
{
    int words = 0, i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i+1] != ' ')
        {
            words++;
        }
    }

    return words + 1;
}

void toLower(char *text)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += 32; // 32 is the ASCII difference between uppercase and lowercase
        }
    }
}

void replaceVowels(char *text)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
        {
            text[i] = '*';
        }
    }
}