//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];
    int count=0,i=0;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter the text you want to count:\n");

    fgets(text, 1000, stdin);

    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]==' ' || text[i]=='\n' || text[i]=='\t')
        {
            count++;
        }
    }

    printf("Word count of the given text is:%d\n", count);

    return 0;
}