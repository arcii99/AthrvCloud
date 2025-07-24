//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h>
#include<string.h>

void main()
{
    char str[100], rev[100];
    int i, j, len, flag = 0;
    
    printf("Enter a string : ");
    scanf("%s", str );
    
    len = strlen(str);
    printf("String Length : %d", len);
    
    for(i = len-1, j=0; i>=0, j < len; i--, j++)
        rev[j] = str[i];
        
    rev[j] = '\0';
    printf("\n Reversed String is : %s ", rev);
    
    
    for(i = 0; i<len; i++)
    {
        if(str[i] != rev[i])
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
        printf("\n %s is a Palindrome String", str);
    else
        printf("\n %s is not a Palindrome String", str);
    
}