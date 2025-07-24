//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum string length
#define MAX_STR_LEN 100

int main()
{
    char str[MAX_STR_LEN];
    int len, i, j;
    int is_palindrome = 1;

    // clear the str array before accepting input
    memset(str, 0, sizeof(str));

    // read input string from user
    printf("Enter a string to check if it's a palindrome:\n");
    gets(str);

    // get length of the input string
    len = strlen(str);

    // loop through the string to check for palindrome
    for(i=0, j=len-1; i<len/2; i++, j--)
    {
        if(str[i] != str[j])
        {
            // string is not a palindrome
            is_palindrome = 0;
            break;
        }
    }

    // print the result
    if(is_palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}