//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_ALIEN_WORD_LEN 25     // Max length of alien word is 25 characters
#define MAX_TRANSLATED_LEN 100    // Max length of translation is 100 characters
#define NUM_LETTERS 26            // Number of letters in the English alphabet

int main()
{
    char alienWord[MAX_ALIEN_WORD_LEN + 1];    // Array to store alien word
    char translated[MAX_TRANSLATED_LEN + 1];   // Array to store translation
    int letterMapping[NUM_LETTERS];            // Letter mapping array to map alien letters to English letters
    int i, j;                                  // Variables for loops

    // Set letter mapping to default values
    for (i = 0; i < NUM_LETTERS; i++)
    {
        letterMapping[i] = -1;   // -1 indicates that letter has not been mapped yet
    }

    printf("Enter alien word to translate: ");
    scanf("%s", alienWord);

    // Loop through the alien word and map each letter to an English letter
    for (i = 0; i < strlen(alienWord); i++)
    {
        int alienLetter = alienWord[i] - 'A';   // Convert alien letter to index 0-25

        if (letterMapping[alienLetter] == -1)   // If letter has not been mapped yet
        {
            char translationLetter;
            printf("Enter English letter for alien letter %c: ", alienWord[i]);
            scanf(" %c", &translationLetter);

            int englishLetter = translationLetter - 'A';  // Convert English letter to index 0-25

            // Check if English letter has already been used for another alien letter
            for (j = 0; j < NUM_LETTERS; j++)
            {
                if (letterMapping[j] == englishLetter)
                {
                    printf("Error: English letter %c has already been used for another alien letter.\n", translationLetter);
                    return 1;
                }
            }

            letterMapping[alienLetter] = englishLetter;   // Map alien letter to English letter
        }
    }

    // Translate alien word to English
    for (i = 0; i < strlen(alienWord); i++)
    {
        int alienLetter = alienWord[i] - 'A';   // Convert alien letter to index 0-25
        int englishLetter = letterMapping[alienLetter];
        if (englishLetter == -1)   // If letter has not been mapped
        {
            printf("Error: Alien letter %c has not been mapped to an English letter.\n", alienWord[i]);
            return 1;
        }
        translated[i] = 'A' + englishLetter;   // Convert English letter index back to letter
    }
    translated[i] = '\0';   // Add null terminator to end of translated string

    printf("\nTranslation: %s\n", translated);

    return 0;
}