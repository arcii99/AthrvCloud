//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char str[MAX_SIZE];
    int len, i, j, flag = 0;
    
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    
    // Remove newline character from the end of string
    if (str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';
    }
    
    len = strlen(str);
    
    // Check for palindrome
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 1;
            break;
        }
    }
    
    if (flag == 0)
    {
        printf("%s is palindrome\n", str);
    }
    else
    {
        printf("%s is not palindrome\n", str);
    }
    
    return 0;
}