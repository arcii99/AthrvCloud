//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    char str[MAX_LENGTH];
    int i, j, len, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < len/2; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);

    return 0;
}