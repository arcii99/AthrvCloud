//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countWords(char *str);

int main()
{
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    int result = countWords(str);
    printf("Total words in the given string: %d\n", result);
    return 0;
}

int countWords(char *str)
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]) || ispunct(str[i]))
        {
            count++;
        }
    }
    return count + 1;
}