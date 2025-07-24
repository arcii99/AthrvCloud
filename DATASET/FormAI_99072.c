//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000], reverse_sentence[1000];
    int i, j, len;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    len = strlen(sentence);

    j = 0;
    for (i = len - 2; i >= 0; i--)
    {
        reverse_sentence[j++] = sentence[i];
    }
    reverse_sentence[j] = '\0';

    // Printing the Input and Reversed Sentences
    printf("\nInput Sentence: %s", sentence);
    printf("\nReversed Sentence: %s", reverse_sentence);

    // Replacing Space with Dash in Input and Reversed Sentence
    for (i = 0; i < len - 1; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '-';
        }
        if (reverse_sentence[i] == ' ')
        {
            reverse_sentence[i] = '-';
        }
    }

    // Printing the Input and Reversed Sentences with Replaced Space
    printf("\n\nInput Sentence with Replaced Space: %s", sentence);
    printf("\nReversed Sentence with Replaced Space: %s", reverse_sentence);

    // Counting the Number of Words in the Input Sentence
    int words = 1;
    for (i = 0; i < len - 1; i++)
    {
        if (sentence[i] == ' ' && sentence[i + 1] != ' ')
        {
            words++;
        }
    }

    printf("\nThe Input Sentence contains %d words.\n", words);

    return 0;
}