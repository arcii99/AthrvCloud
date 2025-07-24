//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100];
    int i, j, len, flag = 0;
    
    printf("Enter a string: ");
    scanf("%[^\n]s", string);
    
    // Convert the string to lowercase
    for (i = 0; string[i]; i++)
        string[i] = tolower(string[i]);
    
    len = strlen(string);
    
    // Check if the string is a palindrome
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (string[i] != string[j])
        {
            flag = 1;
            break;
        }
    }
    
    if (flag)
        printf("%s is not a palindrome.\n", string);
    else
        printf("%s is a palindrome.\n", string);
    
    return 0;
}