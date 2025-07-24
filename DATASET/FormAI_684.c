//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int length,i,j,flag=0;
    
    printf("Enter a word/string: ");
    scanf("%s",word);
    
    length = strlen(word);
    
    for(i=0,j=length-1;i<length/2;i++,j--)
    {
        if(word[i]!=word[j])
        {
            flag = 1;
            break;
        }
    }
    
    if(flag==1)
    {
        printf("%s is not a palindrome.",word);
    }
    else
    {
        printf("%s is a palindrome.",word);
    }
    
    return 0;
}