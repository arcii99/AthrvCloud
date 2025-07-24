//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int i, j, k;
    printf("Welcome to the Cat Language Translator!\n");
    printf("Please enter the sentence you want to translate:\n");
    fgets(sentence, 100, stdin);

    // Translate "C" sounds to "Meow"
    for (i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == 'c' || sentence[i] == 'C')
        {
            sentence[i] = 'm';
            // Shift the characters after 'c' for the length of "meow" minus 1(3)
            for (j = i + 1, k = 0; k < 3 && sentence[j] != '\0'; j++, k++)
            {
                sentence[j] = 'e';
            }
            sentence[j - 1] = 'o';
            sentence[j] = 'w';
        }
    }

    printf("\nTranslation complete: \n%s\n", sentence);

    return 0;
}