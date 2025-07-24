//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count_words(char *str);

int main(void)
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    int count = count_words(str);
    printf("Number of words in the string: %d\n", count);

    return 0;
}

int count_words(char *str)
{
    int count = 0;
    int flag = 0; // 0=word not started, 1=word started

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            count++;
        }
    }

    return count;
}