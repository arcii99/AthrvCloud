//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    int words = 1;
    int i;
    
    printf("Enter the string: ");
    gets(str);
    
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            words++;
    }
    
    printf("The number of words in the string are: %d", words);
    
    return 0;
}