//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

void summarize(char text[])
{
    // Find the length of the text
    int length = strlen(text);

    // Remove all the punctuations from the text
    for (int i = 0; i < length; i++)
    {
        if (ispunct(text[i]))
        {
            text[i] = ' ';
        }
    }

    // Tokenize the text into sentences
    char *sentence = strtok(text, ".");
    while (sentence != NULL)
    {
        // Tokenize the sentence into words
        char *word = strtok(sentence, " ");
        int count = 0;
        while (word != NULL)
        {
            // Check if the word is a stop word
            char *stop_words[] = {"the", "a", "an", "and", "but", "or", "for", "nor", "on", "at", "to", "from", "by", "with", "in", "out", "over", "under"};
            int stop_word_found = 0;
            for (int i = 0; i < 18; i++)
            {
                if (strcmp(word, stop_words[i]) == 0)
                {
                    stop_word_found = 1;
                    break;
                }
            }

            // If the word is not a stop word, count it
            if (!stop_word_found)
            {
                count++;
            }

            // Move to the next word
            word = strtok(NULL, " ");
        }

        // Print the summary of the sentence
        if (count > 0)
        {
            printf("%s.\n", sentence);
        }

        // Move to the next sentence
        sentence = strtok(NULL, ".");
    }
}

int main()
{
    // Input the text to be summarized
    char text[] = "Two households, both alike in dignity, In fair Verona, where we lay our scene, From ancient grudge break to new mutiny, Where civil blood makes civil hands unclean. From forth the fatal loins of these two foes A pair of star-crossed lovers take their life, Whose misadventured piteous overthrows Doth with their death bury their parents' strife.";

    // Summarize the text
    summarize(text);

    return 0;
}