//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// This program counts the number of words in a file.

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    int is_word = 0;
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        if (isspace(c))
            is_word = 0;
        else if (!is_word)
        {
            word_count++;
            is_word = 1;
        }
    }

    printf("The file \"%s\" has %d words.\n", argv[1], word_count);

    fclose(file);
    exit(EXIT_SUCCESS);
}