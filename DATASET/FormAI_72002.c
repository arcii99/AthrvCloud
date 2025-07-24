//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int count_words(char *str);

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    int count = count_words(str);

    printf("The word frequency for string \"%s\" is:\n", str);
    printf("=======================================\n");

    // array of words and their frequencies
    char words[MAX][MAX];
    int freq[MAX] = {0};
    int w_count = 0;

    // split string into words and count frequency
    char *token = strtok(str, " \t\n");
    while (token != NULL)
    {
        // check if word is already in array
        int found = 0;
        for (int i = 0; i < w_count; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // add word to array if not already present
        if (!found)
        {
            strcpy(words[w_count], token);
            freq[w_count]++;
            w_count++;
        }

        token = strtok(NULL, " \t\n");
    }

    // print word frequency table
    for (int i = 0; i < w_count; i++)
    {
        printf("%20s : %d\n", words[i], freq[i]);
    }

    return 0;
}

// function to count the number of words in a string
int count_words(char *str)
{
    int count = 0;
    int len = strlen(str);

    // iterate over string
    for (int i = 0; i < len; i++)
    {
        // check for whitespace or new line
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && (i > 0 && str[i-1] != ' ' && str[i-1] != '\n' && str[i-1] != '\t'))
        {
            count++;
        }
    }

    // handle special case where last character is not a whitespace
    if (len > 0 && str[len-1] != ' ' && str[len-1] != '\n' && str[len-1] != '\t')
    {
        count++;
    }

    return count;
}