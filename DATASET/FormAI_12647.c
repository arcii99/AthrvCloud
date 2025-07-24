//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[500], word[100], c;
    int i, j, len, count = 0;

    printf("Welcome to the Happy C Word Count Tool!\n");
    printf("Enter your string below:\n");

    fgets(input, sizeof(input), stdin);

    len = strlen(input);

    if (len == 0 || (len == 1 && input[0] == '\n'))
    {
        printf("Oops! Your input is empty.\n");
        return 0;
    }

    printf("\nProcessing...\n");

    for (i = 0; i <= len; i++)
    {
        c = input[i];
        if (isalpha(c) || c == '-')
        {
            word[j++] = c;
        }
        else if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
        {
            word[j] = '\0';
            if (strlen(word) > 0)
            {
                count++;
            }
            j = 0;
        }
    }

    printf("\nCongrats! Word count complete.\n");
    printf("There are %d words in your input.\n", count);

    return 0;
}