//FormAI DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50];
    int length, i, j;

    printf("Enter a string: ");
    scanf("%s", str1);

    length = strlen(str1);

    for (i = 0, j = length - 1; i < length; i++, j--)
    {
        str2[i] = str1[j];
    }

    str2[length] = '\0';

    printf("Original String: %s\n", str1);
    printf("Reversed String: %s\n", str2);

    if (strcmp(str1, str2) == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}