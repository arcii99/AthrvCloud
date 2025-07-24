//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: active
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], reverse_str[100];
    int len=0, i;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0; i<len; i++)
    {
        reverse_str[i] = str[len-i-1];
    }

    reverse_str[i]='\0';

    if(strcmp(str, reverse_str)==0)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}