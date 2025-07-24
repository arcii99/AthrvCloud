//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
/*
* Linus Torvalds style spelling correction program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_DICT_SIZE 100000

char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE];
int dict_size = 0;

void add_word_to_dict(char *word)
{
    strncpy(dictionary[dict_size], word, MAX_WORD_SIZE);
    dict_size++;
}

int is_word_in_dict(char *word)
{
    int i;
    for (i = 0; i < dict_size; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            return 1; // match found
        }
    }
    return 0; // match not found
}

void load_dict()
{
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_SIZE];
    while (fgets(word, MAX_WORD_SIZE, fp))
    {
        add_word_to_dict(word);
    }
    fclose(fp);
}

void correct_spelling(char *word)
{
    int i, len;
    char org_word[MAX_WORD_SIZE];

    strncpy(org_word, word, MAX_WORD_SIZE);
    len = strlen(word);

    for (i = 0; i < len; i++)
    {
        // check for each possible replacement
        word[i] = 'a';
        if (is_word_in_dict(word))
        {
            return;
        }
        strcpy(word, org_word);

        word[i] = 'e';
        if (is_word_in_dict(word))
        {
            return;
        }
        strcpy(word, org_word);

        word[i] = 'i';
        if (is_word_in_dict(word))
        {
            return;
        }
        strcpy(word, org_word);

        word[i] = 'o';
        if (is_word_in_dict(word))
        {
            return;
        }
        strcpy(word, org_word);

        word[i] = 'u';
        if (is_word_in_dict(word))
        {
            return;
        }
        strcpy(word, org_word);
    }

    printf("No suitable match found for the word %s\n", org_word);
}

int main()
{
    char input_word[MAX_WORD_SIZE];

    load_dict();

    printf("Enter a word to check spelling: ");
    fgets(input_word, MAX_WORD_SIZE, stdin);

    // remove the newline character added by fgets
    input_word[strlen(input_word)-1] = '\0';

    if (is_word_in_dict(input_word))
    {
        printf("The spelling of the word %s is correct.\n", input_word);
    }
    else
    {
        printf("The spelling of the word %s is incorrect.\n", input_word);
        correct_spelling(input_word);
    }

    return 0;
}