//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>

int isPalindrome(char *);

int main()
{
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    if(isPalindrome(word))
        printf("%s is a palindrome.\n", word);
    else
        printf("%s is not a palindrome.\n", word);

    return 0;
}

int isPalindrome(char *word)
{
    int i, j;
    int len = strlen(word);

    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        if(word[i] != word[j])
            return 0;
    }

    return 1;
}