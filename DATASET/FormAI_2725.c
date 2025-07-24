//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, len, flag=0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    len = strlen(str)-1;

    for(i=0,j=len-1; i<j; i++,j--)
    {
        if(str[i]!=str[j])
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}