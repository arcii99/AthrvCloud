//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];          // maximum input length of string is 100
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);    // get input string from user
    int len = strlen(str) - 1;         // store length of input string, excluding '\n' character
    
    // to check if the input string is a palindrome, ignore the spaces and punctuation marks and convert all letters to lowercase
    char new_str[len+1];   // create new string of same length as input string to store filtered characters
    int j=0;               // index for new string
    for(int i=0; i<len; i++)
    {
        if(isalpha(str[i]))            // check if current character is an alphabet
        {
            new_str[j] = tolower(str[i]);   // convert current alphabet to lowercase and add to new string
            j++;                    // increment index of new string
        }
    }
    new_str[j] = '\0';      // add null character at end of new string to indicate end of string
    
    // check if the filtered string is palindrome or not
    int flag=0;     // initialize flag to indicate not palindrome
    for(int i=0; i<=strlen(new_str)/2; i++)
    {
        if(new_str[i] != new_str[len-i-1])   // compare characters from start and end of string
        {
            flag=1;     // if characters are not same, set flag to indicate not palindrome
            break;      // exit the loop as soon as non-palindrome is detected
        }
    }
    
    // print output based on palindrome or not
    if(flag)
        printf("\nThe input string is not a palindrome.\n");
    else
        printf("\nThe input string is a palindrome.\n");
    
    return 0;
}