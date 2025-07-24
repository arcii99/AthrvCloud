//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main()
{
    char word[50];
    int i, length;
    int flag = 1;

    printf("Enter a word: ");
    scanf("%s", word);

    length = strlen(word);

    for (i = 0; i < length; i++)
    {
        if (word[i] != word[length-i-1])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("The word \"%s\" is a palindrome!", word);
    else
        printf("The word \"%s\" is not a palindrome.", word);

    return 0;
}