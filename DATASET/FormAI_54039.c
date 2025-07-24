//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include<stdio.h>
#include<string.h>

int main()
{
    char str[50];
    int length, flag = 0;

    printf("Enter a string (max 50 characters): ");
    gets(str);

    length = strlen(str);

    for(int i=0; i<length; i++)
    {
        if(str[i] != str[length-i-1])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("%s is a palindrome.\n",str);
    }
    else
    {
        printf("%s is not a palindrome.\n",str);
    }

    return 0;
}