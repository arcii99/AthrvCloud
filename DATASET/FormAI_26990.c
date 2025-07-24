//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char word[50];
    int i, j, flag = 1;

    printf("Enter a word: ");
    scanf("%s", word);

    for (i = 0, j = strlen(word) - 1; i < j; i++, j--) 
    {
        if (tolower(word[i]) != tolower(word[j])) //ignores case sensitivity
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("%s is a palindrome.\n", word);
    else
        printf("%s is not a palindrome.\n", word);

    return 0;
}