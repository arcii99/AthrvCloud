//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countWords(char *);
int isChar(char);

int main()
{
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    countWords(input);
    return 0;
}

void countWords(char *input)
{
    int count = 0;
    int i;
    for(i=0; input[i]!='\0'; i++)
    {
        if(isChar(input[i]))
        {
            count++;
            while(isChar(input[i]) && input[i]!='\0')
            {
                i++;
            }
        }
    }
    printf("Total number of words in the string: %d\n", count);
}

int isChar(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    return 0;
}