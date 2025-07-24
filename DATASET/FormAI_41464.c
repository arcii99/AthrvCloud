//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int main()
{
    char input[MAX_SIZE];
    int c_count = 0, word_count = 0, i = 0;

    printf("Enter the string: ");
    fgets(input, MAX_SIZE, stdin);

    while (input[i] != '\0')
    {
        if (isalpha(input[i]))
        {
            c_count++;
        }
        if (isspace(input[i]) || input[i] == '\n')
        {
            if (c_count > 0)
            {
                word_count++;
                c_count = 0;
            }
        }
        i++;
    }

    if (c_count > 0)
    {
        word_count++;
    }

    printf("Number of words: %d", word_count);

    return 0;
}