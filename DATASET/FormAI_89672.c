//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s", word);
    
    int start = 0;
    int end = strlen(word) - 1;
    int isPalindrome = 1;
    
    while (end > start)
    {
        if (word[start++] != word[end--])
        {
            isPalindrome = 0;
            break;
        }
    }
    
    if (isPalindrome)
    {
        printf("\n%s is a palindrome.\n\n", word);
    }
    else
    {
        printf("\n%s is not a palindrome.\n\n", word);
    }
    
    return 0;
}