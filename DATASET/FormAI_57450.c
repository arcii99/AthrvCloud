//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s", word);
    int length = strlen(word);
    int i, j;
    int flag = 1;
    
    for (i = 0, j = length - 1; i < j; ++i, --j)
    {
        if (word[i] != word[j])
        {
            flag = 0;
            break;
        }
    }
    
    if (flag)
    {
        printf("%s is a palindrome!\n", word);
    }
    else
    {
        printf("%s is not a palindrome :(\n", word);
    }
    
    return 0;
}