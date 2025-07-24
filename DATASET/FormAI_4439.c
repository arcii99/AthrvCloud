//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char phrase[] = "Hello World!";
    char newPhrase[20];
    int i, j = 0;

    // Reverse the characters in the string
    for (i = strlen(phrase) - 1; i >= 0; i--)
    {
        newPhrase[j] = phrase[i];
        j++;
    }
    newPhrase[j] = '\0';

    printf("Reversed String: %s\n", newPhrase);

    // Find all vowels in the string
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    for (i = 0; i < strlen(phrase); i++)
    {
        if (phrase[i] == 'a' || phrase[i] == 'A')
            countA++;
        else if (phrase[i] == 'e' || phrase[i] == 'E')
            countE++;
        else if (phrase[i] == 'i' || phrase[i] == 'I')
            countI++;
        else if (phrase[i] == 'o' || phrase[i] == 'O')
            countO++;
        else if (phrase[i] == 'u' || phrase[i] == 'U')
            countU++;
    }

    printf("Number of (A) in phrase: %d\n", countA);
    printf("Number of (E) in phrase: %d\n", countE);
    printf("Number of (I) in phrase: %d\n", countI);
    printf("Number of (O) in phrase: %d\n", countO);
    printf("Number of (U) in phrase: %d\n", countU);

    // Replace all spaces in the string with underscores
    for (i = 0; i < strlen(phrase); i++)
    {
        if (phrase[i] == ' ')
            phrase[i] = '_';
    }

    printf("Modified String: %s\n", phrase);

    // Replace all vowels in the string with dollar signs
    for (i = 0; i < strlen(phrase); i++)
    {
        if (phrase[i] == 'a' || phrase[i] == 'A')
            phrase[i] = '$';
        else if (phrase[i] == 'e' || phrase[i] == 'E')
            phrase[i] = '$';
        else if (phrase[i] == 'i' || phrase[i] == 'I')
            phrase[i] = '$';
        else if (phrase[i] == 'o' || phrase[i] == 'O')
            phrase[i] = '$';
        else if (phrase[i] == 'u' || phrase[i] == 'U')
            phrase[i] = '$';
    }

    printf("Final Modified String: %s\n", phrase);

    return 0;
}