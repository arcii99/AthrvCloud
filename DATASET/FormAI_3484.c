//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <string.h>

/* 
   Hurray! This is a special C Palindrome Checker program!
   It will check whether your inputted word is a palindrome word or not!
*/

int main()
{
    char word[100];
    int length, i, j, flag = 0;
    
    printf("Welcome, let's check if your word is palindrome or not!\n");
    printf("Please enter your word:");
    scanf("%s", word);
    
    length = strlen(word);
    
    for(i=0, j=length-1; i<length/2; i++, j--)
    {
        if(word[i] != word[j])
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1)
    {
        printf("\nOops! %s is not a palindrome word!\n", word);
    }
    else
    {
        printf("\nCongratulations! %s is a palindrome word!\n", word);
    }
    
    return 0;
}