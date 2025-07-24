//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    int total_words = 0;
    int i=0, j=0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            total_words++;
        }
        i++;
    }
    total_words++;

    char arr[total_words][100];
    i=0;
    while(str[i] != '\0')
    {
        j=0;
        while(str[i]!=' ' && str[i] != '\0')
        {
            arr[total_words-1][j] = str[i];
            i++;
            j++;
        }
        arr[total_words-1][j]='\0';
        total_words--;
        if(str[i]!='\0')
        {
            i++;
        }
    }

    for(i=0; i<total_words; i++)
    {
      printf("%s\n", arr[i]);
    }

    return 0;
}