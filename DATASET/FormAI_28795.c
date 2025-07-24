//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int i, j, length;
    printf("Welcome to Palindrome Checker!\n");
    printf("Enter a word to check if it is a palindrome:");
    scanf("%s", word);

    length = strlen(word);

    for (i = 0, j = length - 1; i < length /2; i++, j--)
    {
        if (word[i] != word[j])
        {
            printf("Sorry, %s is not a palindrome. :(\n", word);
            return 0;
        }
    }

    printf("Congratulations! %s is a palindrome! :)\n", word);

    return 0;
}