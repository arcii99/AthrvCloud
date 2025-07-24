//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// function to check if a character is a letter or a digit
int is_alphanumeric(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// function to convert all characters in a string to lowercase
void to_lowercase(char *str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main()
{
    char text[10000]; // maximum size of input text
    printf("Enter your text:\n");
    fgets(text, 10000, stdin); // read input text from user

    char *words[MAX_WORDS]; // array of pointers to store individual words
    int frequencies[MAX_WORDS]; // array to store the frequency of each word
    int num_words = 0; // number of words in the input text

    // tokenize the input text into individual words
    char *tok = strtok(text, " ,.!?\n");
    while (tok != NULL)
    {
        // filter out non-letter and non-digit characters
        int i = 0;
        char filtered_word[MAX_WORD_LENGTH];
        while (tok[i] && i < MAX_WORD_LENGTH - 1)
        {
            if (is_alphanumeric(tok[i]))
                filtered_word[i] = tok[i];
            else
                filtered_word[i] = '\0'; // terminate the string
            i++;
        }
        filtered_word[i] = '\0'; // terminate the string

        // convert the word to lowercase
        to_lowercase(filtered_word);

        if (strlen(filtered_word) > 0)
        {
            // check if the word already exists in the array
            int found = 0;
            int j;
            for (j = 0; j < num_words; j++)
            {
                if (strcmp(filtered_word, words[j]) == 0)
                {
                    frequencies[j]++;
                    found = 1;
                    break;
                }
            }
            // if the word is not found, add it to the array
            if (!found && num_words < MAX_WORDS)
            {
                words[num_words] = malloc(strlen(filtered_word) + 1);
                strcpy(words[num_words], filtered_word);
                frequencies[num_words] = 1;
                num_words++;
            }
        }
        tok = strtok(NULL, " ,.!?\n");
    }

    // print the word frequency table
    printf("Word Frequency Table:\n");
    printf("%-15s %-10s\n", "Word", "Frequency");
    printf("========================\n");
    int k;
    for (k = 0; k < num_words; k++)
    {
        printf("%-15s %-10d\n", words[k], frequencies[k]);
        free(words[k]); // free the memory allocated for each word
    }

    return 0;
}