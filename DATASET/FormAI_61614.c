//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100], rev_str[100]; 
    int i, j, length;
    printf("Hey there! I am a palindrome checker. Give me a word or a sentence and I will tell you if it is a palindrome or not.\n");
    printf("Enter a word or a sentence: ");
    gets(str);
    length = strlen(str);
    j=0;
    for(i=length-1; i>=0; i--)
    {
        rev_str[j++] = str[i];
    }
    rev_str[j] = '\0';
    
    if(strcmp(str, rev_str) == 0)
    {
        printf("Well done! Your input is a palindrome. \n");
        printf("You are definitely smarter than the average human. \n");
    }
    else
    {
        printf("Sorry buddy, your input is not a palindrome. \n");
        printf("What's wrong? Don't worry. Keep trying. \n");
        printf("Wait, don't leave yet. Let me show you how close you were: %s \n", rev_str);
    }
    printf("Thanks for using me! \n");
    return 0;
}