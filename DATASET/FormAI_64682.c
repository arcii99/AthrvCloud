//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
// Welcome to the happy C Palindrome Checker!

#include <stdio.h>
#include <string.h>
#define MAX 100

int isPalindrome(char[]);

int main()
{
    printf("Hello there! I'm your happy C Palindrome Checker!\n");
    
    char word[MAX];
    int result;
    
    printf("Give me a word to check: ");
    fgets(word,MAX,stdin);  // getting user input
    
    result = isPalindrome(word);
    
    if(result == 1) // if the return value from the function is 1, then it's a Palindrome
        printf("\n\nHooray! %s is a Palindrome!\n",word);
    else // if the return value is 0, then it's not a Palindrome
        printf("\n\nAwww! %s is NOT a Palindrome.\n",word);
    
    printf("Thank you for using the happy C Palindrome Checker! Have a great day!");
    return 0;
}

int isPalindrome(char string[])
{
    int length = strlen(string)-1;  // getting length of string (-1 because of null terminator)
    char reversed[length];
    int i, j;
    
    for(i=0, j=length-1; i<length; i++, j--)
    {
        reversed[i] = string[j];
    }
    
    if(strcmp(string,reversed) == 0) // comparing the original with the reverse
        return 1; // it's a Palindrome
    else
        return 0; // it's not a Palindrome
}