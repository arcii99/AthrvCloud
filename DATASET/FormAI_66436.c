//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char str[MAX_SIZE];
    int i, len;
    int flag = 0;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("\n%s is not a Palindrome", str);
    }
    else
    {
        printf("\n%s is a Palindrome", str);
    }

    return 0;
}