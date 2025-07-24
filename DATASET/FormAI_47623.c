//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

int main()
{
    char str[MAX_LENGTH], strRev[MAX_LENGTH];
    int len, i, j, flag;

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);        // read string from user input
    len = strlen(str) - 1;                // exclude new line character

    // convert string to lower case and remove non-alphanumeric characters
    for(i = 0, j = 0; i < len; i++)
    {
        if(isalnum(str[i]))
        {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';                        // terminate string

    // create reverse of input string
    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        strRev[j] = str[i];
    }
    strRev[j] = '\0';                     // terminate string

    // compare original and reverse strings
    if(strcmp(str, strRev) == 0)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    // print result
    if(flag == 1)
    {
        printf("'%s' is a palindrome.\n", str);
    }
    else
    {
        printf("'%s' is not a palindrome.\n", str);
    }

    return 0;
}