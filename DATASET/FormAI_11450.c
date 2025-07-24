//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Define an example sentence to be spell checked
    char sentence[] = "Ths sntnc hs sum wrds speld wrng.";

    // Define an array of correctly spelled words
    char dictionary[][20] = {"this", "sentence", "has", "some", "words", "spelled", "wrong"};

    // Define an array of misspelled words found in the sentence
    char misspelled[20][20] = {0};

    // Loop through each word in the sentence
    int i = 0, j = 0, k = 0;
    while (sentence[i] != '\0')
    {
        // Check if the current character is a letter
        if (isalpha(sentence[i]))
        {
            // Add the letter to the current word being checked
            misspelled[j][k] = tolower(sentence[i]);
            k++;
        }
        else
        {
            // Check if the current word being checked is in the dictionary
            int found = 0;
            for (int l = 0; l < sizeof(dictionary) / sizeof(dictionary[0]); l++)
            {
                if (strcmp(misspelled[j], dictionary[l]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            // If the current word is not in the dictionary, print it as misspelled
            if (!found)
            {
                printf("Misspelled word: %s\n", misspelled[j]);
            }

            // Move on to the next word in the sentence
            j++;
            k = 0;
            memset(misspelled[j], 0, sizeof(misspelled[j]));
        }

        i++;
    }

    return 0;
}