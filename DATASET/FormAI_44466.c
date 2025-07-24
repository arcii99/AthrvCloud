//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
// A spell checking program in C
// Written in the style of Alan Turing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICT_SIZE 1000
#define MAX_INPUT_LEN 200

char dictionary[DICT_SIZE][MAX_WORD_LEN];

void load_dict();

int main()
{
    printf("Welcome to the spell checking program!\n\n");

    char input[MAX_INPUT_LEN];
    load_dict();

    while (1)
    {
        printf("Enter a word to check (hit enter to quit): ");
        fgets(input, MAX_INPUT_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        int word_found = 0;
        for (int i = 0; i < DICT_SIZE; i++)
        {
            if (strcmp(input, dictionary[i]) == 0)
            {
                printf("%s: correct spelling!\n", input);
                word_found = 1;
                break;
            }
        }

        if (!word_found)
        {
            printf("%s: incorrect spelling!\n", input);
        }
    }

    return 0;
}

void load_dict()
{
    FILE *fp = fopen("dictionary.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open dictionary file.");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    int i = 0;

    while (fgets(word, MAX_WORD_LEN, fp) != NULL && i < DICT_SIZE)
    {
        word[strcspn(word, "\n")] = '\0';
        strncpy(dictionary[i], word, MAX_WORD_LEN);
        i++;
    }

    fclose(fp);

    printf("Dictionary loaded with %d words.\n\n", i);
}