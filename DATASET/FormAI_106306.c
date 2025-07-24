//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

int main()
{
    char c;
    int wordCount = 0;
    int wordLength = 0;
    int wordIndex = 0;
    char words[MAX_WORDS][MAX_LENGTH];
    int frequency[MAX_WORDS] = { 0 };
    
    printf("Enter some text:\n");
    
    // Read input character by character and ignore non-alpha characters
    while ((c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            if (wordLength == 0)
            {
                // Start of a new word
                wordIndex = wordCount;
                wordCount++;
            }
            words[wordIndex][wordLength++] = tolower(c);
        }
        else
        {
            // End of a word
            if (wordLength > 0)
            {
                words[wordIndex][wordLength] = '\0';
                wordLength = 0;
            }
        }
    }
    
    // Count the frequency of each word
    int i, j;
    for (i = 0; i < wordCount; i++)
    {
        for (j = 0; j < wordCount; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency[i]++;
            }
        }
    }
    
    // Print the results
    printf("Word\t\tFrequency\n");
    printf("=====================================\n");
    for (i = 0; i < wordCount; i++)
    {
        if (frequency[i] != 0)
        {
            printf("%-15s %d\n", words[i], frequency[i]);
        }
    }
    
    return 0;
}