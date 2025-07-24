//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>

int count_word(char *, char *);

int main()
{
    char string[1000], word[1000];
    int count;

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    printf("Enter a word: ");
    fgets(word, 1000, stdin);

    count = count_word(string, word);

    printf("The word %s occurs %d times in the string.", word, count);

    return 0;
}

int count_word(char *string, char *word)
{
    int i, j, found, count = 0;
    int string_len = strlen(string);
    int word_len = strlen(word);

    for (i = 0; i <= string_len - word_len; i++)
    {
        found = 1;
        for (j = 0; j < word_len; j++)
        {
            if (string[i+j] != word[j])
            {
                found = 0;
                break;
            }           
        }
        if (found == 1)
        {
            count++;
        }
    }

    return count;
}