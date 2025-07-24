//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: careful
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100 //maximum length of string

int main()
{
    char str[MAX_SIZE];
    int i, len, flag;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    flag = 0;

    for(i=0;i<len;i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 1;
            break;
        }
    }

    if(flag==1)
    {
        printf("%s is not a Palindrome\n",str);
    }
    else
    {
        printf("%s is a Palindrome\n",str);
    }

    return 0;
}