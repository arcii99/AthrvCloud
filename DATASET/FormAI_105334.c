//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int i, length;
    int flag = 1;

    printf("Enter a word: ");
    scanf("%s", word);

    length = strlen(word);
    
    for(i=0;i<length/2;i++)
    {
        if(word[i] != word[length-i-1])
        {
            flag=0;
            break;
        }
    }

    if(flag == 1)
        printf("%s is a palindrome.\n", word);
    else
        printf("%s is not a palindrome.\n", word);

    return 0;
}