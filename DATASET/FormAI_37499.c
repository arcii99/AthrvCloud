//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
/* My Unique Ada Lovelace Style C Text Processing Example Program*/

#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    int vowels = 0, consonants = 0, spaces = 0, digits = 0, symbols = 0;

    printf("Enter any text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
            vowels++;
        else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            consonants++;
        else if (text[i] >= '0' && text[i] <= '9')
            digits++;
        else if (text[i] == ' ')
            spaces++;
        else
            symbols++;
    }

    printf("\n\n==== Text Statistics ====\n");

    printf("\nVowels: %d", vowels);
    printf("\nConsonants: %d", consonants);
    printf("\nDigits: %d", digits);
    printf("\nSpaces: %d", spaces);
    printf("\nSymbols: %d", symbols);

    return 0;
}