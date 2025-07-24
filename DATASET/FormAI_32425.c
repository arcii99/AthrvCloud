//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    // Count number of words
    int num_words = 0;
    char *token = strtok(text, " ");
    while(token != NULL)
    {
        num_words++;
        token = strtok(NULL, " ");
    }

    // Reversing the string
    int n = strlen(text);
    char reverse_text[n+1];
    for(int i=0; i<n; i++)
    {
        reverse_text[i] = text[n-i-1];
    }
    reverse_text[n] = '\0';

    // Removing vowels
    char text_without_vowels[n+1];
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(text[i] != 'a' && text[i] != 'e' && text[i] != 'i' && text[i] != 'o' && text[i] != 'u'
        && text[i] != 'A' && text[i] != 'E' && text[i] != 'I' && text[i] != 'O' && text[i] != 'U')
        {
            text_without_vowels[j++] = text[i];
        }
    }
    text_without_vowels[j] = '\0';

    // Displaying the results
    printf("Number of words in the text: %d\n", num_words);
    printf("Reversed text: %s\n", reverse_text);
    printf("Text without vowels: %s\n", text_without_vowels);

    return 0;
}