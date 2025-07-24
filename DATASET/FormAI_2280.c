//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char original[100], reverse[100];
    int i, j, length;
    int flag = 0;

    printf("Enter a string: ");
    fgets(original, 100, stdin);

    length = strlen(original);

    j = 0;
    for (i = length - 1; i >= 0; i--)
    {
        if (isalpha(original[i]))
        {
            reverse[j++] = tolower(original[i]);
        }
    }
    reverse[j] = '\0';

    for (i = 0; i < length; i++)
    {
        if (isalpha(original[i]))
        {
            if (tolower(original[i]) != reverse[length - i - 1])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1)
    {
        printf("'%s' is not a palindrome.\n", original);
    }
    else
    {
        printf("'%s' is a palindrome.\n", original);
    }

    return 0;
}