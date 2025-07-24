//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palindrome(char *str, int len)
{
    int i, j;
    char reversed[len];

    for (i = len - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = str[i];

    reversed[j] = '\0';

    if (strcasecmp(str, reversed) == 0)
        printf("The string %s is palindrome.\n", str);
    else
        printf("The string %s is not palindrome.\n", str);
}

int main()
{
    char str[50];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    printf("\n");
    palindrome(str, len);

    return 0;
}