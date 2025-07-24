//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *text, char *word)
{
    int count = 0;
    char *token = strtok(text, " ,.-?!;:");

    while (token != NULL)
    {
        if (strcmp(token, word) == 0)
            count++;
        token = strtok(NULL, " ,.-?!;:");
    }
    return count;
}

int main()
{
    char text[1000];
    char word[50];

    printf("Enter text: ");
    fgets(text, 1000, stdin);
    printf("Enter word to count frequency of: ");
    scanf("%s", word);

    int count = countWords(text, word);

    printf("\nThe word '%s' appears %d times in the text.", word, count);

    return 0;
}