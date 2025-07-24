//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORDS_PER_LINE 20

// Function to remove leading and trailing spaces from a string
void trim(char *str)
{
    int length = strlen(str);

    //remove leading spaces
    while (*str == ' ')
    {
        str++;
        length--;
    }

    // remove trailing spaces
    while (length > 0 && str[length - 1] == ' ')
        length--;

    str[length] = '\0';
}

int main()
{
    char line[MAX_LINE_LENGTH];
    char words[MAX_WORDS_PER_LINE][MAX_WORD_LENGTH];
    int num_words;
    int i, j;

    // Prompt user for a sentence
    printf("Enter a sentence: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    // Split the sentence into words
    char *token = strtok(line, " ");
    num_words = 0;
    while (token != NULL && num_words < MAX_WORDS_PER_LINE)
    {
        strcpy(words[num_words], token);
        trim(words[num_words]);
        num_words++;
        token = strtok(NULL, " ");
    }

    // Print out the words in reverse order
    printf("The words in reverse order are:\n");
    for (i = num_words - 1; i >= 0; i--)
        printf("%s ", words[i]);
    printf("\n");

    return 0;
}