//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <string.h>

int main()
{
    char word[50];
    int length, i, palindrome = 0;
    
    printf("Enter a word: ");
    scanf("%s", word); //get input word
    
    length = strlen(word); //get length of word
    
    for(i=0; i < length/2; i++)
    {
        if(word[i] != word[length-i-1]) //compare left half and right half
        {
            palindrome = 1;
            break;
        }
    }
    
    if (palindrome == 0)
    {
        printf("It is a palindrome!\n");
        printf("You are a clever one! Your word is the same backwards as forwards!\n");
    }
    else
    {
        printf("It is not a palindrome!\n");
        printf("I'm sorry, your word is not the same backwards as forwards.\n");
    }
    
    return 0; //exit program
}