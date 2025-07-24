//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_text[10000];
    int count[26] = {0};
    int i, j, len;
    char c;

    printf("Please enter the text: \n");
    fgets(input_text, sizeof(input_text), stdin);

    len = strlen(input_text);

    for (i = 0; i < len; i++)
    {
        c = tolower(input_text[i]);

        if (isalpha(c))
        {
            count[c - 'a']++;
        }
    }

    printf("\nWord frequency in the entered text:\n");

    for (i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c occurred %d times.\n", i + 'a', count[i]);
        }
    }

    printf("\nThis program computes the frequency of words in a given text. But what is a word, really? Is it a collection of letters strung together, or something more? And what is frequency? Is it a measure of occurrence, or of significance? These are questions that we cannot answer here, but we can certainly count the letters in a text, and the number of times each one occurs. And in this way, we can gain some insights into the nature of language, and of ourselves.\n");

    return 0;
}