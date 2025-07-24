//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char str[1000], c;
    int count[26] = {0}, i, len;
    
    printf("Enter a string:\n");
    fgets(str, 1000, stdin); 
    
    len = strlen(str);
    
    for(i=0;i<len;i++)
    {
        c = str[i];
        if(isalpha(c))
        {
            c = tolower(c);
            count[c-'a']++;
        }
    }
    
    printf("Character frequency:\n");
    
    for(i=0;i<26;i++)
    {
        if(count[i]>0)
            printf("%c - %d\n", i+'a', count[i]);
    }
    
    return 0;
}