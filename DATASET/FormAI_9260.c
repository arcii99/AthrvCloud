//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_COUNT 1000
#define MAX_WORD_LENGTH 50

void print_word_frequency(char words[MAX_WORD_COUNT][MAX_WORD_LENGTH], int frequency[MAX_WORD_COUNT], int count);

int main()
{
    char text[1000];
    char* words[MAX_WORD_COUNT];
    int frequency[MAX_WORD_COUNT] = { 0 };
    int count = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Convert input text to lowercase
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
    }

    // Get individual words from input text
    char* token = strtok(text, " ,.-\n");

    while (token != NULL)
    {
        // Add new word to words array if not already present
        int word_index = -1;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                word_index = i;
                break;
            }
        }

        if (word_index == -1)
        {
            word_index = count;
            words[count] = token;
            count++;
        }

        // Update frequency count for word
        frequency[word_index]++;

        token = strtok(NULL, " ,.-\n");
    }

    // Print word frequency table
    print_word_frequency(words, frequency, count);

    // Free memory allocated for words array
    for (int i = 0; i < count; i++)
    {
        free(words[i]);
    }

    return 0;
}

void print_word_frequency(char words[MAX_WORD_COUNT][MAX_WORD_LENGTH], int frequency[MAX_WORD_COUNT], int count)
{
    printf("\nWord Frequency Table\n");
    printf("---------------------\n");
    printf("Word \t\t Frequency\n");
    printf("---------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-15s %d\n", words[i], frequency[i]);
    }
}