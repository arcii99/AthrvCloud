//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum length of a dictionary word
#define MAX_WORD_LENGTH 50

// Max number of words in the dictionary
#define MAX_DICTIONARY_WORDS 100000

// Declaration of spell check function
int check_spelling(const char* word, const char (*dictionary)[MAX_WORD_LENGTH], int dictionary_size);

int main(int argc, char* argv[])
{
    // Declare variables for dictionary file and dictionary array
    FILE* dictionary_file;
    char buffer[MAX_WORD_LENGTH];
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int dictionary_size = 0;

    // Declare variables for text file and text buffer
    FILE* text_file;
    char text_buffer[MAX_WORD_LENGTH];
    int num_words_checked = 0;
    int num_mispelled_words = 0;

    // Check for command line arguments
    if (argc != 3)
    {
        printf("Usage: spell_check dictionary_file text_file\n");
        return 1;
    }

    // Read in the dictionary
    dictionary_file = fopen(argv[1], "r");
    if (dictionary_file == NULL)
    {
        printf("Error opening dictionary file %s\n", argv[1]);
        return 1;
    }
    while (fgets(buffer, MAX_WORD_LENGTH, dictionary_file) != NULL)
    {
        // Remove newline character and convert to lowercase
        buffer[strcspn(buffer, "\n")] = '\0';
        for (int i = 0; i < strlen(buffer); i++)
        {
            buffer[i] = tolower(buffer[i]);
        }
        // Copy word into dictionary array and increment dictionary size
        strcpy(dictionary[dictionary_size], buffer);
        dictionary_size++;
    }
    fclose(dictionary_file);

    // Read in the text file and check for misspelled words
    text_file = fopen(argv[2], "r");
    if (text_file == NULL)
    {
        printf("Error opening text file %s\n", argv[2]);
        return 1;
    }
    while (fscanf(text_file, "%s", text_buffer) == 1)
    {
        // Remove non-alphabetic characters and convert to lowercase
        int i = 0;
        int j = 0;
        while (text_buffer[i])
        {
            if (isalpha(text_buffer[i]))
            {
                text_buffer[j] = tolower(text_buffer[i]);
                j++;
            }
            i++;
        }
        text_buffer[j] = '\0';
        // Check if word is misspelled and increment counters
        if (!check_spelling(text_buffer, dictionary, dictionary_size))
        {
            printf("Misspelled word: %s\n", text_buffer);
            num_mispelled_words++;
        }
        num_words_checked++;
    }
    fclose(text_file);

    // Print final results
    printf("Words checked: %d\n", num_words_checked);
    printf("Misspelled words: %d\n", num_mispelled_words);
    return 0;
}

// Implementation of spell check function
int check_spelling(const char* word, const char (*dictionary)[MAX_WORD_LENGTH], int dictionary_size)
{
    int lower = 0;
    int upper = dictionary_size - 1;
    while (lower <= upper)
    {
        int middle = (lower + upper) / 2;
        int comparison_result = strcmp(word, dictionary[middle]);
        if (comparison_result == 0)
        {
            return 1;
        }
        else if (comparison_result < 0)
        {
            upper = middle - 1;
        }
        else
        {
            lower = middle + 1;
        }
    }
    return 0;
}