//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS];
    int i, j, k, n;
 
    printf("Enter a piece of text:\n");
    
    // read text from user input
    n = 0;
    while (scanf("%s", text[n]) != EOF && n < MAX_WORDS)
        ++n;
 
    for (i = 0; i < n; ++i)
    {
        count[i] = 1;

        for (j = i + 1; j < n; ++j)
        {
            if (strcmp(text[i], text[j]) == 0)
            {
                ++count[i];
                text[j][0] = '\0'; // mark the duplicate as empty string
            }
        }
    }

    // print the word frequencies
    printf("\nWord frequencies:\n");
    printf("-----------------\n");
    for (i = 0; i < n; ++i)
    {
        if (text[i][0] != '\0')
        {
            printf("%s : %d\n", text[i], count[i]);
        }
    }
 
    return 0;
}