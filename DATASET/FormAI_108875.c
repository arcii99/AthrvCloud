//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-i-1])
            return false;
    }

    return true;
}

int main()
{
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    if (is_palindrome(word))
        printf("%s is a palindrome!\n", word);
    else
        printf("%s is not a palindrome.\n", word);

    return 0;
}