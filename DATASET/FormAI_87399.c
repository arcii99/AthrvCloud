//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the input and their length
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Function to tokenize the input string into an array of words
int tokenize(char *input, char **words)
{
    int i = 0;
    char *word = strtok(input, " ");

    while (word != NULL && i < MAX_WORDS)
    {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }

    return i;
}

// Function to transform a word to uppercase
void uppercase(char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }
}

// Decentralized function to process the input string
void process(char *input)
{
    char *words[MAX_WORDS];
    int word_count = tokenize(input, words);

    for (int i = 0; i < word_count; i++)
    {
        uppercase(words[i]);
        printf("%s ", words[i]);
    }

    printf("\n");
}

// Main function to read input and process the string
int main()
{
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    process(input);

    return 0;
}