//FormAI DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int countWords(char *string);

int main()
{
    char string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    printf("The word count of your string is: %d\n", countWords(string));
    return 0;
}

int countWords(char *string)
{
    int words = 0;
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t')
        {
            words++;
        }
    }

    return words + 1;
}