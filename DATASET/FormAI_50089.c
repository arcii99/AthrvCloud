//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int word_count(char* s)
{
    int count = 0;
    int len = strlen(s);
    int i = 0;
    
    while(i < len)
    {
        if(s[i] == ' ')
        {
            while(s[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            count++;
            while(i < len && s[i] != ' ')
            {
                i++;
            }
        }
    }
    
    return count;
}

int main()
{
    char input[1000];
    
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    
    int count = word_count(input);
    
    printf("Word count: %d\n", count);
    
    return 0;
}