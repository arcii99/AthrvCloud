//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int i, j, len, flag;    
    printf("Enter a word: ");
    scanf("%s", word);    
    len = strlen(word);

    flag = 1;
    for(i=0, j=len-1; i<len/2; i++, j--)
    {
        if(word[i] != word[j])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        printf("%s is a palindrome", word);
    }
    else
    {
        printf("%s is not a palindrome", word);
    }
    return 0;
}