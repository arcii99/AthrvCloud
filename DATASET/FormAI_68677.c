//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    int len = strlen(str);

    char *new_str = (char*) malloc(sizeof(char) * len);
    int index = 0;

    for(int i = 0; i < len; i++)
    {
        if(isalpha(str[i]))
        {
          new_str[index++] = tolower(str[i]);
        }
    }

    len = index;
    int is_palindrome = 1;

    for(int i = 0; i < len/2; i++)
    {
        if(new_str[i] != new_str[len-i-1])
        {
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome == 1)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
    
    free(new_str);

    return 0;
}