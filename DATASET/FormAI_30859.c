//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int count_words(char *sentence);

int main()
{
    char sentence[MAX_LENGTH];
    int num_words;
    
    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);
    num_words = count_words(sentence);
    
    printf("The sentence '%s' has %d words.\n", sentence, num_words);
    
    return 0;
}

int count_words(char *sentence)
{
    int num_words = 0, i;
    int length = strlen(sentence);
    
    // Handling whitespace at the beginning of the sentence
    while (sentence[0] == ' ')
        sentence++;
    
    for (i = 0; i < length; i++)
    {
        if (sentence[i] == ' ')
        {
            num_words++;
            // Handling multiple spaces between words
            while (sentence[i] == ' ')
                i++;
        }
    }
    
    // Handling the last word in the sentence
    if (sentence[length - 1] != ' ')
        num_words++;
    
    return num_words;
}