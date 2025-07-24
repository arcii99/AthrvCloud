//FormAI DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program is a spell checking application that compares an input user word with 
  a dictionary stored in 'words.txt' in the same directory as the executable.
  If the word exists in the dictionary, it is considered spelled correctly, otherwise, 
  it is considered misspelled and it suggests a correction to the user.
*/

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 5000

/* function prototypes */
void remove_newline(char* word);
int read_words(char* filename, char* words[]);
int compare(const void* a, const void* b);
int binary_search(char* word, char* words[], int num_words);

int main()
{
    char* words[MAX_DICTIONARY_SIZE];
    char user_word[MAX_WORD_LENGTH];
    int num_words;

    /* load words from dictionary into memory */
    num_words = read_words("words.txt", words);
    if(num_words == -1)
    {
        printf("Error reading file.\n");
        return 1;
    }

    /* sort words in alphabetical order */
    qsort(words, num_words, sizeof(char*), compare);

    /* get user input */
    printf("Enter a word: ");
    fgets(user_word, MAX_WORD_LENGTH, stdin);
    remove_newline(user_word);

    /* perform binary search */
    int index = binary_search(user_word, words, num_words);

    /* output result */
    if(index >= 0)
    {
        printf("'%s' is spelled correctly.\n", user_word);
    }
    else
    {
        /* get suggested correction */
        char* suggestion = NULL;
        int i;
        char temp_word[MAX_WORD_LENGTH];
        for(i = 0; i < strlen(user_word); i++)
        {
            /* delete each letter to get new word to compare */
            strcpy(temp_word, user_word);
            memmove(&temp_word[i], &temp_word[i+1], strlen(temp_word)-i);
            int temp_index = binary_search(temp_word, words, num_words);
            if(temp_index >= 0)
            {
                suggestion = temp_word;
                break;
            }
        }
        if(suggestion != NULL)
        {
            printf("'%s' is misspelled. Did you mean '%s'?\n", user_word, suggestion);
        }
        else
        {
            printf("'%s' is misspelled. No suggestions found.\n", user_word);
        }
    }

    /* free memory */
    int i;
    for(i = 0; i < num_words; i++)
    {
        free(words[i]);
    }

    return 0;
}

/* remove newline character from end of string */
void remove_newline(char* word)
{
    char* newline = strchr(word, '\n');
    if(newline != NULL)
    {
        *newline = '\0';
    }
}

/* read words from file into memory */
int read_words(char* filename, char* words[])
{
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        return -1;
    }

    char buffer[MAX_WORD_LENGTH];
    int i = 0;
    while(fgets(buffer, MAX_WORD_LENGTH, file) != NULL && i < MAX_DICTIONARY_SIZE)
    {
        /* remove newline character */
        remove_newline(buffer);

        /* allocate memory for word and copy into array */
        words[i] = malloc(strlen(buffer) + 1);
        strcpy(words[i], buffer);
        i++;
    }

    fclose(file);
    return i;
}

/* compare function for qsort */
int compare(const void* a, const void* b)
{
    const char** word1 = (const char**)a;
    const char** word2 = (const char**)b;
    return strcmp(*word1, *word2);
}

/* binary search for word in array */
int binary_search(char* word, char* words[], int num_words)
{
    int left = 0;
    int right = num_words - 1;

    while(left <= right)
    {
        int middle = (left + right) / 2;
        int comparison = strcmp(word, words[middle]);

        if(comparison == 0)
        {
            return middle;
        }
        else if(comparison < 0)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return -1;
}