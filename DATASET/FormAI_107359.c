//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    char word[100];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    printf("Enter the word to count: ");
    scanf("%s", word);

    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            count++;
        }
    }

    printf("Total words: %d\n", count);

    count = 0;
    char *temp;
    temp = strtok(str, " ");
    while(temp != NULL)
    {
        if(strcmp(temp, word) == 0)
        {
            count++;
        }
        temp = strtok(NULL, " ");
    }

    printf("Total occurrences of word \"%s\": %d\n", word, count);

    return 0;
}