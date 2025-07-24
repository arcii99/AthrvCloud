//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i, j, k;

    printf("Enter a sentence in the Alien Language: ");
    fgets(input, 100, stdin);

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for (i = 0; i < strlen(input); i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (input[i] == vowels[j])
            {
                for (k = i; k < strlen(input) - 1; k++)
                {
                    input[k] = input[k + 1];
                }
                input[k] = '\0';
                i--;
            }
        }
    }

    printf("Translated sentence: %s\n", input);

    return 0;
}